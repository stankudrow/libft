use libc::{c_void, write};
use std::os::unix::io::RawFd;

#[cfg(unix)]
pub fn ft_putchar_fd(c: u8, fd: RawFd) {
    unsafe {
        write(fd, &c as *const u8 as *const c_void, 1);
    }
}

#[cfg(unix)]
pub fn ft_putstr_fd(s: &str, fd: RawFd) {
    assert!(s.is_ascii(), "expected ASCII-string only");
    unsafe {
        write(fd, s.as_bytes().as_ptr() as *const c_void, s.len());
    }
}

#[cfg(unix)]
pub fn ft_putendl_fd(s: &str, fd: RawFd) {
    ft_putstr_fd(s, fd);
    ft_putchar_fd(b'\n', fd);
}

#[cfg(unix)]
pub fn ft_putnbr_fd(nbr: i32, fd: RawFd) {
    if nbr < 0 {
        ft_putchar_fd(b'-', fd);
        if nbr <= -10 {
            ft_putnbr_fd(nbr / -10, fd);
        }
        ft_putchar_fd((-(nbr % 10)) as u8 + b'0', fd);
    } else {
        if nbr >= 10 {
            ft_putnbr_fd(nbr / 10, fd);
        }
        ft_putchar_fd((nbr % 10) as u8 + b'0', fd);
    }
}
