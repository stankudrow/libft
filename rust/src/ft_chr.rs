// If my goal had been to reproduce the "original" ft_isascii function,
// its signature would have been `pub fn ft_isascii(c: i32) -> i32`,
// but I don't chase that goal
pub fn ft_isascii(c: u8) -> bool {
    // `c >= 0` is redundant when c is unsigned
    c <= 127
}
