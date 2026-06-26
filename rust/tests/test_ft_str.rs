use libft::ft_strlen;

#[test]
fn test_empty() {
    assert_eq!(ft_strlen(""), 0);
}

#[test]
fn test_ascii_only() {
    assert_eq!(ft_strlen("hello"), 5);
}

#[test]
fn test_utf8_byte_length() {
    let s = "Привет";
    assert!(ft_strlen(s) > s.chars().count());
}
