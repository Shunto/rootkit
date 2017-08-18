#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>

#define PROCNAME "driver/modtest"
#define MAXBUF 64

static char modtest_buf[MAXBUF];
static int buflen;

/*static ssize_t proc_write(struct file *filp, const char *buf, size_t size, loff_t *off){ 
    if (len >= MAXBUF) {
        printk(KERN_WARNING "proc_write len = %lu\n", len);
        return -ENOSPC;
    }

    if (copy_from_user(modtest_buf, buf, len)) return -EFAULT;

    modtest_buf[len] = '\0';
    buflen = len;

    printk(KERN_INFO "proc_write %s\n", modtest_buf);

    return len;
}

static ssize_t proc_read(char *page, const char **start, size_t size, loff_t *off){ 
    unsigned long outbyte = 0;

    if (offset > 0) {
        *eof = 1;
        return 0;
    }

    outbyte = sprintf(page, "%s", modtest_buf);
    printk(KERN_INFO "proc_read len = %lu\n", outbyte);
    *eof = 1;
    return outbyte;
}*/

static ssize_t proc_write(struct file *fp, const char *buf, size_t size, loff_t *off){
    printk("write\n");
    return size;
}
static ssize_t proc_read(struct file *fp, char *buf, size_t size, loff_t *off){
    printk("read\n");
    return size;
}
static struct file_operations proc_file_fops = {
    .owner = THIS_MODULE,
    .read = proc_read,
    .write = proc_write,
};

static int __init modtest_module_init(void)
{
    struct proc_dir_entry *entry;
    /*struct file_operations proc_file_fops = {

        owner: THIS_MODULE
        read: proc_read
        write: proc_write
        };*/


    entry = proc_create(PROCNAME, 0, NULL, &proc_file_fops);
    printk(KERN_INFO "modtest is loaded\n");
    return 0;
}

static void __exit modtest_module_exit( void )
{
    remove_proc_entry(PROCNAME, NULL);
    printk(KERN_INFO "modtest is removed\n");
}

module_init( modtest_module_init );
module_exit( modtest_module_exit );

MODULE_DESCRIPTION( "modtest" );
MODULE_LICENSE ( "GPL2" );
