// `pub mod XXX;`
// `mod`ule (file) XXX is claimed to exist.
// `pub` makes this module public, i.e. visible from the outside.

pub mod ft_chr;
pub mod ft_str;

pub use ft_chr::ft_isascii;
pub use ft_str::ft_strlen;
