#ifndef _WPUNIX_H
#define _WPUNIX_H

#include <pwd.h>
#include <shadow.h>
#include <grp.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <sys/resource.h>
#include <sys/times.h>
#include <sys/uio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <signal.h>
#include <stdio.h>
#include <limits.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <dirent.h>
#include <utime.h>

struct passwd *wp_getpwuid (uid_t uid);
struct passwd *wp_getpwanam (const char *name);
struct passwd *wp_getpwent (void);

struct spwd *wp_getspnam (const char *name);
struct spwd *wp_getspent (void);

struct group *wp_getgrgid (gid_t gid);
struct group *wp_getgrnam (const char *name);
struct group *wp_getgrent (void);

int wp_getgroups (int gidsetsize, gid_t grouplist[]);
int wp_setgroups (int ngroups, const gid_t grouplist[]);
int wp_initgroups (const char *username, gid_t basegid);

int wp_uname (struct utsname *name);
int wp_gethostname (char *name, int namelen);

int wp_getrlimit (int resource, struct rlimit *rlptr);
int wp_setrlimit (int resource, const struct rlimit *rlptr);

pid_t wp_fork (void);
pid_t wp_wait (int *statloc);
pid_t wp_waitpid (pid_t pid, int *statloc, int options);

int wp_setuid (uid_t uid);
int wp_setgid (gid_t gid);
int wp_setreuid (uid_t ruid, uid_t euid);
int wp_setregid (gid_t rgid, gid_t egid);
int wp_seteuid (uid_t uid);
int wp_setegid (gid_t gid);

int wp_system (const char *cmd);

char *wp_getlogin (void);

clock_t wp_times (struct tms *buf);

int wp_setpgid (pid_t pid, pid_t pgid);

pid_t wp_setsid (void);
pid_t wp_getsid (pid_t pid);

void (*wp_signal (int signo, void (*func)(int)))(int);

int wp_kill (pid_t pid, int signo);
int wp_raise (int signo);

int wp_sigemptyset (sigset_t *set);
int wp_sigfillset (sigset_t *set);
int wp_sigaddset (sigset_t *set, int signo);
int wp_sigdelset (sigset_t *set, int signo);
int wp_sigismember (const sigset_t *set, int signo);
int wp_sigprocmask (int how, const sigset_t *set, sigset_t *oset);
int wp_sigpending (sigset_t *set);
int wp_sigaction (int signo, const struct sigaction *act, struct sigaction *oact);

int wp_sigsuspend (const sigset_t *sigmask);

int wp_sigwait (const sigset_t *set, int *signop);

ssize_t wp_readv (int filedes, const struct iovec *iov, int iovcnt);
ssize_t wp_writev (int filedes, const struct iovec *iov, int iovcnt);

void *wp_mmap (void *addr, size_t len, int prot, int flag, int filedes, off_t off);
int wp_mprotect (void *addr, size_t len, int prot);
int wp_msync (void *addr, size_t len, int flags);
int wp_munmap (caddr_t addr, size_t len);

int wp_pipe (int filedes[2]);

int wp_mkfifo (const char *pathname, mode_t mode);

key_t wp_ftok (const char *path, int id);

int wp_msgget (key_t key, int flag);
int wp_msgctl (int msqid, int cmd, struct msqid_ds *buf);
int wp_msgsnd (int msqid, const void *ptr, size_t nbytes, int flag);
ssize_t wp_msgrcv (int msqid, void *ptr, size_t nbytes, long type, int flag);

int wp_semget (key_t key, int nsems, int flag);
#if 0
int wp_semctl (int semid, int semnum, int cmd, union semun arg);
#endif
int wp_semop (int semid, struct sembuf semoparray[], size_t nops);

int wp_shmctl (int shmid, int cmd, struct shmid_ds *buf);
void *wp_shmat (int shmid, const void *addr, int flag);
int wp_shmdt (void *addr);

/* utilities */
void wp_check_exit_status (int status);
ssize_t wp_readn (int fd, void *ptr, size_t n);
ssize_t wp_writen (int fd, void *ptr, size_t n);

/************************************
 * wpfileio
 ***********************************/

#ifdef __USE_UNIX98
/* aton operate, lseek and read/write */
ssize_t wp_pread (int filedes, void *buf, size_t nbytes, off_t offset);
ssize_t wp_pwrite (int filedes, void *but, size_t nbytes, off_t offset);
#endif /* __USE_UNIX98 */


/***************************************
 * wp file io
 **************************************/
int wp_access (const char *pathname, int mode);
int wp_chmod (const char *pathname, mode_t mode);
int wp_chown (const char *pathname, uid_t owner, gid_t group);
int wp_close (int filedes);
int wp_creat (const char *pathname, mode_t mode);
int wp_dup (int filedes);
int wp_dup2 (int filedes, int filedes2);

int wp_fchmod (int filedes, mode_t mode);
int wp_fchown (int filedes, uid_t user, gid_t group);
int wp_fcntl (int filedes, int cmd, int arg);
int wp_fdatasync (int filedes);
int wp_fstat (int filedes, struct stat *buf);
int wp_fsync (int filedes);
int wp_ftruncate (int filedes, off_t length);
int wp_ioctl (int filedes, int request, void *arg);
off_t wp_lseek (int filedes, off_t offset, int whence);
int wp_lchown (const char *pathname, uid_t owenr, gid_t group);
int wp_link (const char *exsitingpath, const char *newpath);
int wp_lstat (const char *pathname, struct stat *buf);
int wp_open (const char *pathname, int oflag, mode_t mode);
ssize_t wp_read (int filedes, void *buf, size_t nbytes);
ssize_t wp_readlink (const char *pathname, char *bug, size_t bufsize);
int wp_stat (const char *pathname, struct stat *buf);
int wp_symlink (const char *actualpath, const char *sympath);
int wp_truncate (const char *pathname, off_t length);
int wp_unlink (const char *pathname);
int wp_utime (const char *pathname, const struct utimbuf *times);
ssize_t wp_write (int filedes, const void *buf, size_t nbytes);

/**************************************
 * wp io utilities
 *************************************/
int wp_fd_create (const char *pathname, mode_t mode);
int wp_fd_alloc (const char *pathname, mode_t mode, off_t offset);
int wp_fd_append (int filedes, off_t offset);

void wp_fd_set_flag (int fd, int flags);
void wp_fd_clear_flag (int fd, int flags);
bool wp_fd_is_flag_set (int fd, int flag);

typedef void (*wp_dopath_func) (const char *path, void *data);
void wp_dopath (char *path, wp_dopath_func func, void *data);

/**************************************
 * wp file utilities
 *************************************/
int wp_chdir (const char *pathname);
int wp_closedir (DIR *dp);
int wp_fchdir (int filedes);

char *wp_getcwd (char *bug, size_t size);
int wp_mkdir (const char *pathname, mode_t mode);
DIR *wp_opendir (const char *pathname);
struct dirent *wp_readdir (DIR *dp);
int wp_rmdir (const char *pathname);

ssize_t wp_readv (int filedes, const struct iovec *iov, int iovcnt);
ssize_t wp_writev (int filedes, const struct iovec *iov, int iovcnt);

/*************************************
 * wp timer utilities
 ************************************/

typedef struct timeval WpTimer;

WpTimer *wp_timer_new ();
void wp_timer_free (WpTimer *t);
void wp_timer_start (WpTimer *t);
double wp_timer_elapse (WpTimer *t);

/* rio */
ssize_t _wp_readn (int fd, void *ptr, size_t n);
ssize_t _wp_writen (int fd, void *ptr, size_t n);

typedef struct _rio Rio;

Rio *_wp_rio_new (int fd);
void _wp_rio_free (Rio* rp);

ssize_t _wp_rio_readlineb (Rio *rp, void *usrbuf, size_t maxlen);
ssize_t _wp_rio_readnb (Rio *rp, void *usrbuf, size_t n);
ssize_t _wp_rio_writen (Rio *rp, void *ptr, size_t n);
#define _wp_rio_readline _wp_rio_readlineb
#define _wp_rio_readnb _wp_rio_readnb

ssize_t wp_readn (int fd, void *ptr, size_t n);
ssize_t wp_writen (int fd, void *ptr, size_t n);

Rio *wp_rio_new (int fd);
void wp_rio_free (Rio* rp);

ssize_t wp_rio_readlineb (Rio *rp, void *usrbuf, size_t maxlen);
ssize_t wp_rio_readnb (Rio *rp, void *usrbuf, size_t n);
ssize_t wp_rio_writen (Rio *rp, void *ptr, size_t n);
#define wp_rio_readline wp_rio_readlineb
#define wp_rio_readnb wp_rio_readnb

int wp_rio_getfd (Rio *rp);

#endif /* _WPUNIX_H */
