// `pub` = public -> is visible from outside this module.
// Without pub this function would have been private.
pub fn ft_strlen(s: &str) -> usize {
    // &str in Rust is UTF-8
    // For ASCII string, `s.len() == s.chars().count()`
    // C-strlen is about chars as bytes, that is why `s.as_bytes()`

    // return s.len(); // return is possible, but redundant
    s.len() // no semicolon here!!!

    // In a function, the last expression is returned automatically
    // If the last expression is followed by a semicolon,
    // then it becomes a statement/instruction that returns nothing (semicolon silences).
}
