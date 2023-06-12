#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Rock Paper Scissors Game");

static char *player_choice = "Rock"; // Default choice is Rock

module_param(player_choice, charp, S_IRUSR | S_IWUSR);

static int __init rock_paper_scissors_init(void)
{
    char *choices[] = { "Rock", "Paper", "Scissors" };
    int num_choices = sizeof(choices) / sizeof(choices[0]);
    int i, bot_choice;
    char *bot_choice_str;
    bool valid_choice = false;

    printk(KERN_INFO "Rock Paper Scissors game initialized\n");

    // Validate player's choice
    for (i = 0; i < num_choices; i++) {
        if (strcmp(player_choice, choices[i]) == 0) {
            valid_choice = true;
            break;
        }
    }

    if (!valid_choice) {
        printk(KERN_INFO "Invalid choice. Choose from Rock, Paper, or Scissors.\n");
        return -EINVAL;
    }

    // Generate bot's choice using random number
    bot_choice = prandom_u32() % num_choices;
    bot_choice_str = choices[bot_choice];

    printk(KERN_INFO "You chose: %s\n", player_choice);
    printk(KERN_INFO "Bot chose: %s\n", bot_choice_str);

    // Find the winner
    if (strcmp(player_choice, bot_choice_str) == 0) {
        printk(KERN_INFO "It's a tie!\n");
    } else if ((strcmp(player_choice, "Rock") == 0 && strcmp(bot_choice_str, "Scissors") == 0) ||
               (strcmp(player_choice, "Paper") == 0 && strcmp(bot_choice_str, "Rock") == 0) ||
               (strcmp(player_choice, "Scissors") == 0 && strcmp(bot_choice_str, "Paper") == 0)) {
        printk(KERN_INFO "You win!\n");
    } else {
        printk(KERN_INFO "Bot wins!\n");
    }

    return 0;
}

static void __exit rock_paper_scissors_exit(void)
{
    printk(KERN_INFO "Rock Paper Scissors game exited\n");
}

module_init(rock_paper_scissors_init);
module_exit(rock_paper_scissors_exit);
