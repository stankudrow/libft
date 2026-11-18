// s is an immutable pointer to a string -> no need for const qualifier
pub fn ft_strlen(s: &str) -> usize {
    assert!(s.is_ascii(), "expected ASCII-string only");
    s.len()
}

pub fn ft_strchr(s: &str, c: u8) -> Option<&str> {
    assert!(s.is_ascii(), "expected ASCII-string only");
    if c == b'\0' {
        return Some(&s[s.len()..]);
    }
    match s.as_bytes().iter().position(|&b| b == c) {
        Some(i) => Some(&s[i..]),
        None => None,
    }
}

pub fn ft_strdup(s: &str) -> String {
    assert!(s.is_ascii(), "expected ASCII-string only");
    String::from(s)
}
