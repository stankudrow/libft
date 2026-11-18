use libft::{ft_strchr, ft_strdup, ft_strlen};

#[cfg(test)]
mod test_strlen {
    use super::*;

    #[test]
    fn test_empty() {
        assert_eq!(ft_strlen(""), 0);
    }

    #[test]
    fn test_ascii() {
        assert_eq!(ft_strlen("hello"), 5);
    }

    #[test]
    #[should_panic(expected = "ASCII")]
    fn test_utf8() {
        ft_strlen("Привет");
    }
}

#[cfg(test)]
mod test_strchr {
    use super::*;

    #[test]
    fn test_first_occurrence() {
        assert_eq!(ft_strchr("hello", b'l'), Some("llo"));
    }

    #[test]
    fn test_first_char() {
        assert_eq!(ft_strchr("abc", b'a'), Some("abc"));
    }

    #[test]
    fn test_not_found() {
        assert_eq!(ft_strchr("abc", b'x'), None);
    }

    #[test]
    fn test_empty_string() {
        assert_eq!(ft_strchr("", b'a'), None);
        assert_eq!(ft_strchr("", b'\0'), Some(""));
    }

    #[test]
    fn test_nul_terminator() {
        assert_eq!(ft_strchr("abc", b'\0'), Some(""));
    }

    #[test]
    #[should_panic(expected = "ASCII")]
    fn test_non_ascii() {
        ft_strchr("Привет", b't');
    }
}

#[cfg(test)]
mod test_strdup {
    use super::*;

    #[test]
    fn test_duplication() {
        assert_eq!(ft_strdup("hello"), "hello");
    }

    #[test]
    fn test_empty() {
        assert_eq!(ft_strdup(""), "");
    }

    #[test]
    fn test_string_copy() {
        let original = String::from("abc");
        let mut copy = ft_strdup(&original);
        copy.push('x');
        assert_eq!(original, "abc");
        assert_eq!(copy, "abcx");
    }

    #[test]
    #[should_panic(expected = "ASCII")]
    fn test_non_ascii() {
        ft_strdup("Привет");
    }
}
