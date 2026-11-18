#[cfg(all(test, unix))]
mod unix_tests {
    use std::io::Read;
    use std::os::fd::{AsRawFd, RawFd};
    use std::os::unix::net::UnixStream;

    use libft::{ft_putchar_fd, ft_putendl_fd, ft_putnbr_fd, ft_putstr_fd};

    fn capture<F: FnOnce(RawFd)>(f: F) -> Vec<u8> {
        let (mut reader, writer) = UnixStream::pair().expect("couldn't create socket pair");
        f(writer.as_raw_fd());
        drop(writer);
        let mut buf = Vec::new();
        reader.read_to_end(&mut buf).expect("reading error");
        buf
    }

    #[test]
    fn test_putchar() {
        let out = capture(|fd| {
            ft_putchar_fd(b'A', fd);
            ft_putchar_fd(b'b', fd);
            ft_putchar_fd(b'3', fd);
        });
        assert_eq!(out, b"Ab3");
    }

    mod putstr {
        use super::*;

        #[test]
        fn test_putstr_writing_a_whole_string() {
            let out = capture(|fd| ft_putstr_fd("hello", fd));
            assert_eq!(out, b"hello");
        }

        #[test]
        fn test_putstr_empty() {
            let out = capture(|fd| ft_putstr_fd("", fd));
            assert!(out.is_empty());
        }
    }

    #[test]
    fn test_putendl() {
        let out = capture(|fd| ft_putendl_fd("hi", fd));
        assert_eq!(out, b"hi\n");
    }

    mod putnbr {
        use super::*;

        #[test]
        fn test_putnbr_positive_number() {
            let out = capture(|fd| ft_putnbr_fd(42, fd));
            assert_eq!(out, b"42");
        }

        #[test]
        fn test_putnbr_digit() {
            assert_eq!(capture(|fd| ft_putnbr_fd(0, fd)), b"0");
            assert_eq!(capture(|fd| ft_putnbr_fd(7, fd)), b"7");
        }

        #[test]
        fn test_putnbr_negative_number() {
            assert_eq!(capture(|fd| ft_putnbr_fd(-42, fd)), b"-42");
            assert_eq!(capture(|fd| ft_putnbr_fd(-7, fd)), b"-7");
        }

        #[test]
        fn test_putnbr_int_min() {
            assert_eq!(capture(|fd| ft_putnbr_fd(i32::MIN, fd)), b"-2147483648");
            assert_eq!(capture(|fd| ft_putnbr_fd(i32::MAX, fd)), b"2147483647");
        }
    }
}
