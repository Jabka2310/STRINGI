#include "mystring.h"

s21_size_t s21_strlen(
    const char *str) {  // Считает длинну строки, возвращает ее в s21_size_t
  s21_size_t lenght = 0;
  while (*str != '\0') {
    lenght++;
    str++;
  }
  return lenght;
}
// ------------------------------------------------------------------------------------------------
char *s21_strncpy(
    char *dest, const char *src,
    s21_size_t n) {  // Копирует строку src в dest, возвращает dest
  char *result = dest;
  s21_size_t i = 0;

  while (i < n && *src != '\0') {
    *dest = *src;
    dest++;
    src++;
    i++;
  }

  while (i < n) {
    *dest = '\0';
    dest++;
    i++;
  }

  return result;
}
// ------------------------------------------------------------------------------------------------
int s21_strncmp(const char *str1, const char *str2,
                s21_size_t n) {  // Сравнивает две строки, возвращает 0 если они
                                 // равны, 1 если
  // первая больше, -1 если вторая больше
  int result = 0;
  s21_size_t i = 0;

  while (i < n && str1[i] != '\0' && str2[i] != '\0' && result == 0) {
    result = (unsigned char)str1[i] - (unsigned char)str2[i];
    i++;
  }

  if (result == 0 && i < n) {
    result = (unsigned char)str1[i] - (unsigned char)str2[i];
  }

  return result;
}
// ------------------------------------------------------------------------------------------------
void *s21_memchr(
    const void *str, int c,
    s21_size_t n) {  // Ищет первое вхождение символа c в строку str, возвращает
  // указатель на этот символ или S21_NULL если символ не найден
  void *result = S21_NULL;
  const unsigned char *p = (const unsigned char *)str;

  while (n-- > 0 && result == S21_NULL) {
    if (*p == (unsigned char)c) {
      result = (void *)p;
    }
    p++;
  }

  return result;
}
// ------------------------------------------------------------------------------------------------
int s21_memcmp(const void *str1, const void *str2,
               s21_size_t n) {  // Сравнивает две области памяти, возвращает 0
                                // если они равны,
  // 1 если первая больше, -1 если вторая больше
  int result = 0;
  const unsigned char *p1 = (const unsigned char *)str1;
  const unsigned char *p2 = (const unsigned char *)str2;

  while (n-- > 0 && result == 0) {
    result = *p1 - *p2;
    p1++;
    p2++;
  }

  return result;
}
// ------------------------------------------------------------------------------------------------
void *s21_memcpy(
    void *dest, const void *src,
    s21_size_t n) {  // Копирует n байт из src в dest, возвращает dest
  char *d = (char *)dest;
  const char *s = (const char *)src;

  while (n--) {
    *d++ = *s++;  // Порядок операций смотри ниже
  }
  //*d = *s;  Копирование байта из *s в *d
  // d++;     Увеличение указателя dest
  // s++;     Увеличение указателя src
  return dest;
}
// ------------------------------------------------------------------------------------------------
void *s21_memset(void *str, int c,
                 s21_size_t n) {  // Заполняет память символом c, возвращает str
  char *p = (char *)str;
  while (n--) {
    *p++ = (char)c;  // ВАЖНО!!!!
    // Не работает с *str, работает только с str[]
    // Так как первое хранится в другой области памяти, а не в стеке
    //  Так же если использовать тип int, то будет ошибка, так как int занимает
    //  4 байта, а char 1 байт Помимо прочего, если задать 10 байт, и задать их
    //  нулями - то зачиститься 3 целых байта вместо 2.5
  }
  return str;
}
// ------------------------------------------------------------------------------------------------
char *s21_strncat(char *dest, const char *src,
                  s21_size_t n) {  // Конкатенирует две строки, возвращает dest
  char *d = dest;

  // Доходим до конца строки
  while (*d != '\0') {
    d++;
  }

  // Копируем не более n символов
  while (n > 0 && *src != '\0') {
    *d++ = *src++;
    n--;
  }

  // Добавляем завершающий нуль
  *d = '\0';

  return dest;
}
// ------------------------------------------------------------------------------------------------
char *s21_strchr(
    const char *str,
    int c) {  // Ищет первое вхождение символа c в строку str, возвращает
              // указатель на этот символ или S21_NULL если символ не найден
  char *result = S21_NULL;

  while (*str != '\0' && result == S21_NULL) {
    if (*str == (unsigned char)c) {
      result = (char *)str;
    }
    str++;
  }

  if (result == S21_NULL && (unsigned char)c == '\0') {
    result = (char *)str;
  }

  return result;
}
// ------------------------------------------------------------------------------------------------
s21_size_t s21_strcspn(
    const char *str1,
    const char *str2) {  // Ищет первое вхождение символа из str2 в str1,
                         // возвращает количество символов до этого вхождения
  s21_size_t result = 0;
  const char *p1 = str1;

  while (*p1 != '\0' && s21_strchr(str2, *p1) == S21_NULL) {
    p1++;
    result++;
  }

  return result;
}
// ------------------------------------------------------------------------------------------------
char *s21_strpbrk(
    const char *str1,
    const char *str2) {  // Ищет первое вхождение символа из str2
                         // в str1, возвращает указатель на этот
                         // символ или S21_NULL если символ не найден
  char *result = S21_NULL;

  while (*str1 != '\0' && result == S21_NULL) {
    const char *p2 = str2;
    while (*p2 != '\0' && result == S21_NULL) {
      if (*str1 == *p2) {
        result = (char *)str1;
      }
      p2++;
    }
    str1++;
  }

  return result;
}
// ------------------------------------------------------------------------------------------------
char *s21_strrchr(
    const char *str,
    int c) {  // Ищет последнее вхождение символа c в строку str, возвращает
              // указатель на этот символ или S21_NULL если символ не найден
  const char *last = S21_NULL;

  while (*str != '\0') {
    if (*str == (unsigned char)c) {
      last = str;
    }
    str++;
  }

  if ((unsigned char)c == '\0') {
    last = str;
  }

  return (char *)last;
}
// ------------------------------------------------------------------------------------------------
char *s21_strstr(
    const char *haystack,
    const char *needle) {  // Ищет первое вхождение строки needle в строку
                           // haystack, возвращает указатель на это вхождение
                           // или S21_NULL если оно не найдено
  char *result = S21_NULL;

  if (*needle == '\0') {
    result = (char *)haystack;
  } else {
    while (*haystack != '\0' && result == S21_NULL) {
      const char *p1 = haystack;
      const char *p2 = needle;

      while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) {
        p1++;
        p2++;
      }

      if (*p2 == '\0') {
        result = (char *)haystack;
      }

      haystack++;
    }
  }

  return result;
}
// ------------------------------------------------------------------------------------------------
char *s21_strtok(
    char *str,
    const char *delim) {  // Разбивает строку на токены по разделителям delim
  static char *last = S21_NULL;
  char *token_start = S21_NULL;

  if (str != S21_NULL) {
    last = str;
  }

  if (last != S21_NULL) {
    // Пропускаем начальные разделители
    while (*last != '\0' && s21_strchr(delim, *last) != S21_NULL) {
      last++;
    }

    if (*last != '\0') {
      token_start = last;

      // Ищем следующий разделитель
      while (*last != '\0' && s21_strchr(delim, *last) == S21_NULL) {
        last++;
      }

      if (*last != '\0') {
        *last = '\0';
        // last++;
      } else {
        last = S21_NULL;
      }
    } else {
      last = S21_NULL;
    }
  }

  return token_start;
}
// ------------------------------------------------------------------------------------------------

// Массивы сообщений об ошибках для macOS и Linux
#ifdef S21_MAC_OS
static const char *s21_error_messages[] = {
    [0] = "Undefined error: 0",
    [EPERM] = "Operation not permitted",
    [ENOENT] = "No such file or directory",
    [ESRCH] = "No such process",
    [EINTR] = "Interrupted system call",
    [EIO] = "Input/output error",
    [ENXIO] = "Device not configured",
    [E2BIG] = "Argument list too long",
    [ENOEXEC] = "Exec format error",
    [EBADF] = "Bad file descriptor",
    [ECHILD] = "No child processes",
    [EDEADLK] = "Resource deadlock avoided",
    [ENOMEM] = "Cannot allocate memory",
    [EACCES] = "Permission denied",
    [EFAULT] = "Bad address",
    [ENOTBLK] = "Block device required",
    [EBUSY] = "Resource busy",
    [EEXIST] = "File exists",
    [EXDEV] = "Cross-device link",
    [ENODEV] = "Operation not supported by device",
    [ENOTDIR] = "Not a directory",
    [EISDIR] = "Is a directory",
    [EINVAL] = "Invalid argument",
    [ENFILE] = "Too many open files in system",
    [EMFILE] = "Too many open files",
    [ENOTTY] = "Inappropriate ioctl for device",
    [ETXTBSY] = "Text file busy",
    [EFBIG] = "File too large",
    [ENOSPC] = "No space left on device",
    [ESPIPE] = "Illegal seek",
    [EROFS] = "Read-only file system",
    [EMLINK] = "Too many links",
    [EPIPE] = "Broken pipe",
    [EDOM] = "Numerical argument out of domain",
    [ERANGE] = "Result too large",
    [EAGAIN] = "Resource temporarily unavailable",
    [EINPROGRESS] = "Operation now in progress",
    [EALREADY] = "Operation already in progress",
    [ENOTSOCK] = "Socket operation on non-socket",
    [EDESTADDRREQ] = "Destination address required",
    [EMSGSIZE] = "Message too long",
    [EPROTOTYPE] = "Protocol wrong type for socket",
    [ENOPROTOOPT] = "Protocol not available",
    [EPROTONOSUPPORT] = "Protocol not supported",
    [ESOCKTNOSUPPORT] = "Socket type not supported",
    [ENOTSUP] = "Operation not supported",
    [EPFNOSUPPORT] = "Protocol family not supported",
    [EAFNOSUPPORT] = "Address family not supported by protocol family",
    [EADDRINUSE] = "Address already in use",
    [EADDRNOTAVAIL] = "Can't assign requested address",
    [ENETDOWN] = "Network is down",
    [ENETUNREACH] = "Network is unreachable",
    [ENETRESET] = "Network dropped connection on reset",
    [ECONNABORTED] = "Software caused connection abort",
    [ECONNRESET] = "Connection reset by peer",
    [ENOBUFS] = "No buffer space available",
    [EISCONN] = "Socket is already connected",
    [ENOTCONN] = "Socket is not connected",
    [ESHUTDOWN] = "Can't send after socket shutdown",
    [ETOOMANYREFS] = "Too many references: can't splice",
    [ETIMEDOUT] = "Operation timed out",
    [ECONNREFUSED] = "Connection refused",
    [ELOOP] = "Too many levels of symbolic links",
    [ENAMETOOLONG] = "File name too long",
    [EHOSTDOWN] = "Host is down",
    [EHOSTUNREACH] = "No route to host",
    [ENOTEMPTY] = "Directory not empty",
    [EPROCLIM] = "Too many processes",
    [EUSERS] = "Too many users",
    [EDQUOT] = "Disk quota exceeded",
    [ESTALE] = "Stale NFS file handle",
    [EREMOTE] = "Too many levels of remote in path",
    [EBADRPC] = "RPC struct is bad",
    [ERPCMISMATCH] = "RPC version wrong",
    [EPROGUNAVAIL] = "RPC prog. not avail",
    [EPROGMISMATCH] = "Program version wrong",
    [EPROCUNAVAIL] = "Bad procedure for program",
    [ENOLCK] = "No locks available",
    [ENOSYS] = "Function not implemented",
    [EFTYPE] = "Inappropriate file type or format",
    [EAUTH] = "Authentication error",
    [ENEEDAUTH] = "Need authenticator",
    [EPWROFF] = "Device power is off",
    [EDEVERR] = "Device error",
    [EOVERFLOW] = "Value too large to be stored in data type",
    [EBADEXEC] = "Bad executable",
    [EBADARCH] = "Bad CPU type in executable",
    [ESHLIBVERS] = "Shared library version mismatch",
    [EBADMACHO] = "Malformed Macho file",
    [ECANCELED] = "Operation canceled",
    [EIDRM] = "Identifier removed",
    [ENOMSG] = "No message of desired type",
    [EILSEQ] = "Illegal byte sequence",
    [ENOATTR] = "Attribute not found",
    [EBADMSG] = "Bad message",
    [EMULTIHOP] = "Reserved",
    [ENODATA] = "No message available on STREAM",
    [ENOLINK] = "Reserved",
    [ENOSR] = "No STREAM resources",
    [ENOSTR] = "Not a STREAM",
    [EPROTO] = "Protocol error",
    [ETIME] = "STREAM ioctl timeout",
    [EOPNOTSUPP] = "Operation not supported on socket",
    [ENOPOLICY] = "No such policy registered",
};
#elif defined(S21_LINUX)
static const char *s21_error_messages[] = {
    [0] = "Success",
    [EPERM] = "Operation not permitted",
    [ENOENT] = "No such file or directory",
    [ESRCH] = "No such process",
    [EINTR] = "Interrupted system call",
    [EIO] = "Input/output error",
    [ENXIO] = "No such device or address",
    [E2BIG] = "Argument list too long",
    [ENOEXEC] = "Exec format error",
    [EBADF] = "Bad file descriptor",
    [ECHILD] = "No child processes",
    [EAGAIN] = "Resource temporarily unavailable",
    [ENOMEM] = "Cannot allocate memory",
    [EACCES] = "Permission denied",
    [EFAULT] = "Bad address",
    [ENOTBLK] = "Block device required",
    [EBUSY] = "Device or resource busy",
    [EEXIST] = "File exists",
    [EXDEV] = "Invalid cross-device link",
    [ENODEV] = "No such device",
    [ENOTDIR] = "Not a directory",
    [EISDIR] = "Is a directory",
    [EINVAL] = "Invalid argument",
    [ENFILE] = "Too many open files in system",
    [EMFILE] = "Too many open files",
    [ENOTTY] = "Inappropriate ioctl for device",
    [ETXTBSY] = "Text file busy",
    [EFBIG] = "File too large",
    [ENOSPC] = "No space left on device",
    [ESPIPE] = "Illegal seek",
    [EROFS] = "Read-only file system",
    [EMLINK] = "Too many links",
    [EPIPE] = "Broken pipe",
    [EDOM] = "Numerical argument out of domain",
    [ERANGE] = "Numerical result out of range",
    [EDEADLK] = "Resource deadlock avoided",
    [ENAMETOOLONG] = "File name too long",
    [ENOLCK] = "No locks available",
    [ENOSYS] = "Function not implemented",
    [ENOTEMPTY] = "Directory not empty",
    [ELOOP] = "Too many levels of symbolic links",
    [ENOMSG] = "No message of desired type",
    [EIDRM] = "Identifier removed",
    [ECHRNG] = "Channel number out of range",
    [EL2NSYNC] = "Level 2 not synchronized",
    [EL3HLT] = "Level 3 halted",
    [EL3RST] = "Level 3 reset",
    [ELNRNG] = "Link number out of range",
    [EUNATCH] = "Protocol driver not attached",
    [ENOCSI] = "No CSI structure available",
    [EL2HLT] = "Level 2 halted",
    [EBADE] = "Invalid exchange",
    [EBADR] = "Invalid request descriptor",
    [EXFULL] = "Exchange full",
    [ENOANO] = "No anode",
    [EBADRQC] = "Invalid request code",
    [EBADSLT] = "Invalid slot",
    // [EDEADLOCK] = "Resource deadlock avoided",
    [EBFONT] = "Bad font file format",
    [ENOSTR] = "Device not a stream",
    [ENODATA] = "No data available",
    [ETIME] = "Timer expired",
    [ENOSR] = "Out of streams resources",
    [ENONET] = "Machine is not on the network",
    [ENOPKG] = "Package not installed",
    [EREMOTE] = "Object is remote",
    [ENOLINK] = "Link has been severed",
    [EADV] = "Advertise error",
    [ESRMNT] = "Srmount error",
    [ECOMM] = "Communication error on send",
    [EPROTO] = "Protocol error",
    [EMULTIHOP] = "Multihop attempted",
    [EDOTDOT] = "RFS specific error",
    [EBADMSG] = "Bad message",
    [EOVERFLOW] = "Value too large for defined data type",
    [ENOTUNIQ] = "Name not unique on network",
    [EBADFD] = "File descriptor in bad state",
    [EREMCHG] = "Remote address changed",
    [ELIBACC] = "Can not access a needed shared library",
    [ELIBBAD] = "Accessing a corrupted shared library",
    [ELIBSCN] = ".lib section in a.out corrupted",
    [ELIBMAX] = "Attempting to link in too many shared libraries",
    [ELIBEXEC] = "Cannot exec a shared library directly",
    [EILSEQ] = "Invalid or incomplete multibyte or wide character",
    [ERESTART] = "Interrupted system call should be restarted",
    [ESTRPIPE] = "Streams pipe error",
    [EUSERS] = "Too many users",
    [ENOTSOCK] = "Socket operation on non-socket",
    [EDESTADDRREQ] = "Destination address required",
    [EMSGSIZE] = "Message too long",
    [EPROTOTYPE] = "Protocol wrong type for socket",
    [ENOPROTOOPT] = "Protocol not available",
    [EPROTONOSUPPORT] = "Protocol not supported",
    [ESOCKTNOSUPPORT] = "Socket type not supported",
    [EOPNOTSUPP] = "Operation not supported",
    [EPFNOSUPPORT] = "Protocol family not supported",
    [EAFNOSUPPORT] = "Address family not supported by protocol",
    [EADDRINUSE] = "Address already in use",
    [EADDRNOTAVAIL] = "Cannot assign requested address",
    [ENETDOWN] = "Network is down",
    [ENETUNREACH] = "Network is unreachable",
    [ENETRESET] = "Network dropped connection on reset",
    [ECONNABORTED] = "Software caused connection abort",
    [ECONNRESET] = "Connection reset by peer",
    [ENOBUFS] = "No buffer space available",
    [EISCONN] = "Transport endpoint is already connected",
    [ENOTCONN] = "Transport endpoint is not connected",
    [ESHUTDOWN] = "Cannot send after transport endpoint shutdown",
    [ETOOMANYREFS] = "Too many references: cannot splice",
    [ETIMEDOUT] = "Connection timed out",
    [ECONNREFUSED] = "Connection refused",
    [EHOSTDOWN] = "Host is down",
    [EHOSTUNREACH] = "No route to host",
    [EALREADY] = "Operation already in progress",
    [EINPROGRESS] = "Operation now in progress",
    [ESTALE] = "Stale file handle",
    [EUCLEAN] = "Structure needs cleaning",
    [ENOTNAM] = "Not a XENIX named type file",
    [ENAVAIL] = "No XENIX semaphores available",
    [EISNAM] = "Is a named type file",
    [EREMOTEIO] = "Remote I/O error",
    [EDQUOT] = "Disk quota exceeded",
    [ENOMEDIUM] = "No medium found",
    [EMEDIUMTYPE] = "Wrong medium type",
    [ECANCELED] = "Operation canceled",
    [ENOKEY] = "Required key not available",
    [EKEYEXPIRED] = "Key has expired",
    [EKEYREVOKED] = "Key has been revoked",
    [EKEYREJECTED] = "Key was rejected by service",
    [EOWNERDEAD] = "Owner died",
    [ENOTRECOVERABLE] = "State not recoverable",
    [ERFKILL] = "Operation not possible due to RF-kill",
    [EHWPOISON] = "Memory page has hardware error",
};
#endif

// Максимальное количество ошибок
#define S21_MAX_ERRNO \
  (sizeof(s21_error_messages) / sizeof(s21_error_messages[0]) - 1)

static char s21_unknown_error[64] = {0};

char *s21_strerror(int errnum) {  // Возвращает строку с ошибкой errnum
  char *result = "Unknown error";
  
  if (errnum >= 0 && errnum <= (int)S21_MAX_ERRNO) {
    const char *msg = s21_error_messages[errnum];
    if (msg) {
      result = (char *)msg;
    }
  } else {
    // snprintf(s21_unknown_error, sizeof(s21_unknown_error), "Unknown error: %d",
    snprintf(s21_unknown_error, sizeof(s21_unknown_error), "Unknown error %d",
             errnum);
    result = s21_unknown_error;
  }

  return result;
}
