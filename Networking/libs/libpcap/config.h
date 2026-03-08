/*
 * config.h - AROS-specific libpcap configuration
 *
 * This replaces the autoconf-generated config.h for AROS builds.
 * AROS uses the Roadshow-compatible BPF API through bsdsocket.library.
 */

#ifndef _PCAP_CONFIG_H
#define _PCAP_CONFIG_H

/* Package information */
#define PACKAGE_NAME "pcap"
#define PACKAGE_VERSION "1.11.0"
#define PACKAGE_STRING "pcap 1.11.0"
#define PACKAGE_BUGREPORT ""

/* Architecture-dependent sizes */
#ifdef __x86_64__
#define SIZEOF_VOID_P 8
#define SIZEOF_TIME_T 4
#elif defined(__i386__)
#define SIZEOF_VOID_P 4
#define SIZEOF_TIME_T 4
#elif defined(__arm__)
#define SIZEOF_VOID_P 4
#define SIZEOF_TIME_T 4
#else
#define SIZEOF_VOID_P 4
#define SIZEOF_TIME_T 4
#endif

/*
 * Headers available on AROS
 */
#define HAVE_UNISTD_H		1
#define HAVE_FCNTL_H		1
#define HAVE_LIMITS_H		1
/* #undef HAVE_SYS_IOCCOM_H */
/* #undef HAVE_SYS_SOCKIO_H */
/* #undef HAVE_NET_IF_MEDIA_H */

/* AROS sockaddr has sa_len */
#define HAVE_STRUCT_SOCKADDR_SA_LEN	1

/* AROS BPF uses regular struct timeval, not a custom bpf_timeval */
/* #undef HAVE_STRUCT_BPF_TIMEVAL */

/*
 * C library functions available on AROS
 */
#define HAVE_STRLCPY		1
#define HAVE_STRLCAT		1
#define HAVE_STRTOK_R		1
#define HAVE_VSNPRINTF		1
#define HAVE_SNPRINTF		1
#define HAVE_FSEEKO		1
/* #undef HAVE_ASPRINTF */
/* #undef HAVE_VASPRINTF */

/* strerror_r is not available; we use strerror() */
/* #undef HAVE_GNU_STRERROR_R */
/* #undef HAVE_POSIX_STRERROR_R */

/* Network functions */
/* #undef HAVE_ETHER_HOSTTON */

/* Flex/Bison generated parser is reentrant */
/* #undef HAVE_PCAP_LEX_DESTROY */

/*
 * BPF support — AROS provides BPF through bsdsocket.library
 * with Roadshow-compatible API
 */
/* #undef HAVE_ZEROCOPY_BPF */
/* #undef HAVE_NET_BPF_H */

/*
 * Platform features NOT available on AROS
 */
/* #undef HAVE_SOLARIS */
/* #undef HAVE_HPUX10_20_OR_LATER */
/* #undef HAVE_DAG_API */
/* #undef HAVE_SNF_API */
/* #undef HAVE_PACKET */
/* #undef PCAP_SUPPORT_LINUX_USBMON */
/* #undef PCAP_SUPPORT_NETFILTER */
/* #undef PCAP_SUPPORT_NETMAP */
/* #undef PCAP_SUPPORT_BT */
/* #undef PCAP_SUPPORT_BT_MONITOR */
/* #undef PCAP_SUPPORT_DBUS */
/* #undef PCAP_SUPPORT_RDMASNIFF */
/* #undef PCAP_SUPPORT_DPDK */
/* #undef ENABLE_REMOTE */

/* No protochain support (simplifies build) */
/* #undef NO_PROTOCHAIN */

/* Debugging */
/* #undef BDEBUG */
/* #undef YYDEBUG */

/* OS-specific protocol header */
#define HAVE_OS_PROTO_H		1

/* AROS uses IFNAMSIZ, not IF_NAMESIZE */
#ifndef IF_NAMESIZE
#define IF_NAMESIZE	IFNAMSIZ
#endif

/*
 * AROS-specific: getaddrinfo/freeaddrinfo/gai_strerror/inet_pton
 * are not in any standard C library on AROS — they are provided
 * through bsdsocket.library as RS_* functions.
 * We supply wrappers in aros_netcompat.c; declare prototypes here
 * so that gencode.c, nametoaddr.c, etc. can use them.
 */
#ifndef __AROS_NETCOMPAT_IMPL__
struct addrinfo;
int  getaddrinfo(const char *, const char *,
		 const struct addrinfo *, struct addrinfo **);
void freeaddrinfo(struct addrinfo *);
const char *gai_strerror(int);
int  inet_pton(int, const char *, void *);
#endif

#endif /* _PCAP_CONFIG_H */
