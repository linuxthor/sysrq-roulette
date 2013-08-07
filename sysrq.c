#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sysrq.h>
#include <linux/random.h>

static void handle_sysrq_do(int key) 
{
    int  cha; 
    char donay[1];
    get_random_bytes(donay,1);
    cha = (int)donay[0];
//  printk("Debug -> %d\n",cha);
    if (cha <= 42 && cha >= 0)
    {
        panic("\n\n!!THANKS FOR PLAYING!!\n\n\n!!WE'LL SEE YOU NEXT TIME!!\n");
    }
    printk("Click!\n");
}
 
static struct sysrq_key_op handle_sysrq_op = 
{
    .handler     = &handle_sysrq_do,
    .help_msg    = "kmem roulette style sysrq handler",
    .action_msg  = "Roulette",
};
 
static int my_init (void)
{
    int ret = register_sysrq_key('a', &handle_sysrq_op);
    printk("[+] Welcome to Roulette! echo a > /proc/sysrq-trigger to play!\n");
    return ret;
}
 
static void my_exit (void)
{
    unregister_sysrq_key('a', &handle_sysrq_op);
}
 
module_init(my_init);
module_exit(my_exit);
 
MODULE_LICENSE ("GPL");
