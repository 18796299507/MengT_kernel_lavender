#ifndef _ELF_RANDOMIZE_H
#define _ELF_RANDOMIZE_H

struct mm_struct;

#ifndef CONFIG_ARCH_HAS_ELF_RANDOMIZE
static inline unsigned long arch_mmap_rnd(void) { return 0; }
# if defined(arch_randomize_brk) && \
	(defined(CONFIG_ASLR_NONE) || defined(CONFIG_ASLR_PARTIAL))
#  define compat_brk_randomized
# endif
# ifndef arch_randomize_brk
#  define arch_randomize_brk(mm)	(mm->brk)
# endif
#else
extern unsigned long arch_mmap_rnd(void);
extern unsigned long arch_randomize_brk(struct mm_struct *mm);
# if defined(CONFIG_ASLR_NONE) || defined(CONFIG_ASLR_PARTIAL)
#  define compat_brk_randomized
# endif
#endif

#endif
