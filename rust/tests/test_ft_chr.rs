use libft::ft_isalnum;
use libft::ft_isalpha;
use libft::ft_isascii;
use libft::ft_isdigit;
use libft::ft_isprint;
use libft::ft_tolower;
use libft::ft_toupper;

#[test]
fn test_ft_isalnum() {
    assert_eq!(ft_isalnum(0), false);
    assert_eq!(ft_isalnum(b'0'), true);
    assert_eq!(ft_isalnum(b'o'), true);
    assert_eq!(ft_isalnum(b'9'), true);
    assert_eq!(ft_isalnum(b'A'), true);
    assert_eq!(ft_isalnum(b'Z'), true);
    assert_eq!(ft_isalnum(b'a'), true);
    assert_eq!(ft_isalnum(b'z'), true);
    assert_eq!(ft_isalnum(128), false);
    assert_eq!(ft_isalnum(255), false);
}

#[test]
fn test_ft_isalpha() {
    assert_eq!(ft_isalpha(0), false);
    assert_eq!(ft_isalpha(b'A'), true);
    assert_eq!(ft_isalpha(b'Z'), true);
    assert_eq!(ft_isalpha(b'a'), true);
    assert_eq!(ft_isalpha(b'z'), true);
    assert_eq!(ft_isalpha(255), false);
}

#[test]
fn test_ft_isascii() {
    assert_eq!(ft_isascii(0), true);
    assert_eq!(ft_isascii(100), true);
    assert_eq!(ft_isascii(127), true);
    assert_eq!(ft_isascii(128), false);
    assert_eq!(ft_isascii(255), false);
}

#[test]
fn test_ft_isdigit() {
    assert_eq!(ft_isdigit(0), false);
    assert_eq!(ft_isdigit(b'0'), true);
    assert_eq!(ft_isdigit(b'9'), true);
    assert_eq!(ft_isdigit(128), false);
    assert_eq!(ft_isdigit(255), false);
}

#[test]
fn test_ft_isprint() {
    assert_eq!(ft_isprint(31), false);
    assert_eq!(ft_isprint(32), true);
    assert_eq!(ft_isprint(100), true);
    assert_eq!(ft_isprint(126), true);
    assert_eq!(ft_isprint(127), false);
}

#[test]
fn test_ft_tolower() {
    assert_eq!(ft_tolower(b'A' - 1), 64);
    assert_eq!(ft_tolower(b'A'), b'a');
    assert_eq!(ft_tolower(b'Z'), b'z');
    assert_eq!(ft_tolower(b'a'), b'a');
    assert_eq!(ft_tolower(b'z'), b'z');
    assert_eq!(ft_tolower(b'z' + 1), 123);
}

#[test]
fn test_ft_toupper() {
    assert_eq!(ft_toupper(b'A' - 1), 64);
    assert_eq!(ft_toupper(b'A'), b'A');
    assert_eq!(ft_toupper(b'Z'), b'Z');
    assert_eq!(ft_toupper(b'a'), b'A');
    assert_eq!(ft_toupper(b'z'), b'Z');
    assert_eq!(ft_toupper(b'z' + 1), 123);
}
