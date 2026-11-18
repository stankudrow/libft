pub mod ft_chr;

pub use ft_chr::ft_isalnum;
pub use ft_chr::ft_isalpha;
pub use ft_chr::ft_isascii;
pub use ft_chr::ft_isdigit;
pub use ft_chr::ft_isprint;
pub use ft_chr::ft_tolower;
pub use ft_chr::ft_toupper;

// The entire module and its imports are UNIX/MacOS-only (Windows ignored)
#[cfg(unix)]
pub mod ft_put_fd;
#[cfg(unix)]
pub use ft_put_fd::{ft_putchar_fd, ft_putendl_fd, ft_putnbr_fd, ft_putstr_fd};

pub mod ft_str;
pub use ft_str::ft_strchr;
pub use ft_str::ft_strdup;
pub use ft_str::ft_strlen;
