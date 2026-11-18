pub fn ft_isascii(c: u8) -> bool {
    c <= 127
}

fn ft_islower(c: u8) -> bool {
    // matches!(c, b'a'..=b'z')
    c.is_ascii_lowercase()
}

fn ft_isupper(c: u8) -> bool {
    // matches!(c, b'A'..=b'Z')
    c.is_ascii_uppercase()
}

pub fn ft_isalnum(c: u8) -> bool {
    ft_isalpha(c) || ft_isdigit(c)
}

pub fn ft_isalpha(c: u8) -> bool {
    ft_islower(c) || ft_isupper(c)
}

// This attribute makes `cargo clippy` happy
#[allow(clippy::needless_return)]
pub fn ft_isdigit(c: u8) -> bool {
    return c.is_ascii_digit();
}

pub fn ft_isprint(c: u8) -> bool {
    // c > 31 && c < 127
    (32..127).contains(&c)
}

pub fn ft_tolower(c: u8) -> u8 {
    if ft_isupper(c) {
        // b'a' - b'A' = 32 in ASCII
        return c + (b'a' - b'A');
    }
    c
}

pub fn ft_toupper(c: u8) -> u8 {
    if ft_islower(c) {
        // b'a' - b'A' = 32 in ASCII
        return c - (b'a' - b'A');
    }
    c
}
