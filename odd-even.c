#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Finding Odd and Even Numbers");

static int numbers[] = {1, 2, 3, 4, 5}; // Example numbers

static int __init odd_even_numbers_init(void)
{
    int i;
    int num_count = sizeof(numbers) / sizeof(numbers[0]);

    printk(KERN_INFO "Odd and Even numbers module initialized\n");

    for (i = 0; i < num_count; i++) {
        if (numbers[i] % 2 == 0)
            printk(KERN_INFO "Number %d is Even\n", numbers[i]);
        else
            printk(KERN_INFO "Number %d is Odd\n", numbers[i]);
    }

    return 0;
}

static void __exit odd_even_numbers_exit(void)
{
    printk(KERN_INFO "Odd and Even numbers module exited\n");
}

module_init(odd_even_numbers_init);
module_exit(odd_even_numbers_exit);
