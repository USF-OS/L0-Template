/**
 * @file lab0.c
 *
 * Lab 0: Getting to Know You
 * --------------------------
 *
 * Welcome! I'm excited to have you in class and am looking forward to getting
 * to know you over the course of the semester. This first lab assignment has
 * two goals:
 *  - For you to tell me a little bit more about yourself
 *  - Trying out the assignment submission process
 *
 * Edit this .c file to provide your responses, make sure it compiles and runs,
 * and then check it into github to submit. That's all there is to it!
 *
 * To compile:
 *  cc lab0.c -o lab0
 *
 * And then run:
 *  ./lab0
 *
 *
 *  Don't have a C compiler on your machine? No problem. You can use:
 *
 *   - https://replit.com/languages/c
 *   - https://pythontutor.com/c.html
 *
 *  ...And probably millions more out on the web. Just be aware that you won't
 *  be able to get away with using an online compiler for the rest of the work
 *  in this class! :-)
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Contains student bio information.
 */
struct student {
    char *usf_username;   /*!< Username you use to sign on to USF services */
    char *preferred_name; /*!< What I should call you (help w/ pronunciation if needed :-) */
    char *pronouns;       /*!< she/her, he/his, they/their, ze/zir, etc. */
    char *about;          /*!< Detailed information about you. */
};

/**
 * Prints a student's information to stdout.
 *
 * @param s student information struct to print.
 * @return 0 on success, nonzero if no username specified
 */
int print_student(struct student *s);

int main(void)
{
    struct student you = { 0 }; // Initialize and zero-out the struct.

    /* --- The following information is REQUIRED. --- */

    you.usf_username = "";

    /* --- The following information is optional. --- */

    you.preferred_name = "";
    you.pronouns = "";

    you.about =
        "Tell me something about yourself (if you want), and anything I can do "
        "to help you succeed this semester. This can include things that help "
        "me accommodate your learning better (e.g., 'I commute from Sacramento "
        "every day in a horse-drawn carriage, so sometimes I might be a bit "
        "late') or if you'd like to stop by and chat about something feel free "
        "to let me know here."
        "\n\n"
        "If you aren't currently registered for the class, please provide "
        "details."
        "\n\n"
        "You might've already known this, but C concatenates strings that are "
        "separated by whitespace. So this giant paragraph is actually just a "
        "single string. However, you can always just fill in your answer as "
        "one long string too. :-)"
        "\n\n"
        "If you aren't going to write anything here, set 'you.about' to be a "
        "blank string or delete this declaration entirely.";

    int status = print_student(&you);
    if (status != 0) {
        fprintf(stderr, "Error: no username specified!\n");
        return EXIT_FAILURE;
    }

    puts("");
    puts("Thanks!");
    puts("Looking forward to a great semester!");

    return 0;
}

int print_student(struct student *s)
{
    if (s->usf_username == NULL || strlen(s->usf_username) == 0) {
        /* No username specified! */
        return 1;
    }
    printf("Username:       %s\n", s->usf_username);

    if (s->preferred_name != NULL && strlen(s->preferred_name) > 0) {
        printf("Preferred:      %s\n", s->preferred_name);
    }

    if (s->pronouns != NULL && strlen(s->pronouns) > 0) {
        printf("Pronouns:       %s\n", s->pronouns);
    }

    if (s->about != NULL && strlen(s->about) > 0) {
        /* Ignore 'about' info if the first few words haven't been changed: */
        char *prefix = "Tell me something";
        if (strncmp(s->about, prefix, strlen(prefix)) != 0) {
            printf("-------------------------------------\n");
            printf("About me: %s\n", s->about);
        }
    }

    return 0;
}
