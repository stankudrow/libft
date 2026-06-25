use libft::ft_isascii;

#[test]
fn test_isascii() {
    assert_eq!(ft_isascii(0), true);
    assert_eq!(ft_isascii(100), true);
    assert_eq!(ft_isascii(127), true);
    assert_eq!(ft_isascii(128), false);
    assert_eq!(ft_isascii(255), false);
}
