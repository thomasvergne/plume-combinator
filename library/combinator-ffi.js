module.exports = {
  is_alphabetic: (c) => 
    /[a-zA-Z]/.test(c),
  is_digit: (c) =>
    /[0-9]/.test(c),
  is_alphanumeric: (c) =>
    /[a-zA-Z]|[0-9]/.test(c),
  is_whitespace: (c) =>
    /\s/.test(c),
  ffi_to_int: (s) => parseInt(s),
  str_split: (s, sep) => s.split(sep),
  which: (s) => {
    const fs = require('fs');
    return fs.existsSync(s) ? s : '';
  },
  str_index(s, i) {
    if (i < 0 || i >= s.length) {
      return None();
    }

    return Some(s[i]);
  },

  explode(s) {
    return s.split('');
  },
}