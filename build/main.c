#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("Dual BSD/GPL");

static char *hello_words = "welcome to linux kernel world!";
static int words_count = 29; 

static int hello_word_init(void)
{
        printk(KERN_INFO " words content:%s\n", hello_words);
        printk(KERN_INFO " words num:%d\n", words_count);
    
        return 0;
}

static void hello_word_exit()
{
        printk(KERN_ALERT " hello word exit\n");
}

module_init(hello_word_init);
module_exit(hello_word_exit);
module_param(words_count, int, S_IRUGO);
module_param(hello_words, charp, S_IRUGO);

MODULE_AUTHOR("eafly huang");
MODULE_DESCRIPTION("A hello word module for testing module parameters");
MODULE_VERSION("V1.0");
