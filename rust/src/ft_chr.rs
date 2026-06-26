// If my goal had been to reproduce the "original" ft_isascii function,
// its signature would have been `pub fn ft_isascii(c: i32) -> i32`,
pub fn ft_isascii(c: u8) -> bool {
    // `c >= 0` is redundant when c is unsigned
    c <= 127 // the result of the last expression is returned automatically
    // however, `return c <= 127;` is doable, yet not idiomatic
}

// A function without `pub` is private -> like `static` in C
fn ft_islower(c: u8) -> bool {
    // c >= b'a' && c <= b'z' // possible, but `cargo clippy` suggests...
    // (b'a'..=b'z').contains(&c) // yet this also does not please clippy, so...
    c.is_ascii_lowercase() // and this makes clippy happy
}

// The following macro will suppress the complain from `cargo clippy`
#[allow(clippy::char_lit_as_u8)]
fn ft_isupper(c: u8) -> bool {
    // explicit type casting via `obj as %type%`
    // because implicit casting is not ppresumed and for good reason
    c >= ('A' as u8) && c <= ('Z' as u8)
}

// No need to declare/define the underlying function before this one
pub fn ft_isalnum(c: u8) -> bool {
    ft_isalpha(c) || ft_isdigit(c)
}

pub fn ft_isalpha(c: u8) -> bool {
    ft_islower(c) || ft_isupper(c)
}

// several "warnings" are silenced in one macro
#[allow(clippy::char_lit_as_u8, clippy::needless_return)]
pub fn ft_isdigit(c: u8) -> bool {
    // b'0' is a byte literal, while '0' is char (Unicode)
    // '0' is char, c is u8 -> incompatible types,
    // either byte literal will do or explicit type casting
    return c >= b'0' && c <= ('9' as u8);
}

#[allow(clippy::needless_return)]
pub fn ft_isprint(c: u8) -> bool {
    return c > 31 && c < 127; // not disallowed, why not `return` redundantly
}

pub fn ft_tolower(c: u8) -> u8 {
    if ft_isupper(c) {
        return c + 32; // here return is necessary
        // because the expression above is not the very last
    }
    c // here the `return` statement can be omitted
}

#[allow(clippy::needless_return)]
pub fn ft_toupper(c: u8) -> u8 {
    if ft_islower(c) {
        return c - 32; // parentheses are unncecessary
    }
    return c;
}
