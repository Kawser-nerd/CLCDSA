#include <stdio.h>
#include <stdlib.h>

struct user {
    int id;
    int is_friend[11];
    int ff_cnt;
    int is_ff[11];
};

struct user user_init(int id)
{
    struct user user;
    user.id = id;
    user.ff_cnt = 0;
    for (int i = 0; i < 11; ++i) {
        user.is_friend[i] = 0;
        user.is_ff[i] = 0;
    }
    return user;
}

void set_friend(struct user *u, int user_id)
{
    if (u->is_friend[user_id]) {
        return;
    }
    u->is_friend[user_id] = 1;
}

void set_ff(struct user *u, int user_id)
{
    if (u->is_ff[user_id]) {
        return;
    }
    u->is_ff[user_id] = 1;
    u->ff_cnt++;
}

int main(int argc, char **argv)
{
    int num_user, num_group, a, b;
    struct user *users;

    scanf("%d %d", &num_user, &num_group);
    users = (struct user *) calloc(num_user + 1, sizeof(struct user));
    for (int i = 0; i <= num_user; ++i) {
        users[i] = user_init(i);
    }
    for (int i = 0; i < num_group; ++i) {
        scanf("%d %d", &a, &b);
        set_friend(&users[a], b);
        set_friend(&users[b], a);
    }

    for (int i = 1; i <= num_user; ++i) {
        for (int j = 1; j <= num_user; ++j) {
            if (i == j) {
                continue;
            }
            if (! users[i].is_friend[j]) {
                continue;
            }
            for (int k = 1; k <= num_user; ++k) {
                if (i == k || j == k) {
                    continue;
                }
                if (! users[j].is_friend[k]) {
                    continue;
                }
                if (users[i].is_friend[k]) {
                    continue;
                }
                set_ff(&users[i], k);
            }
        }
        printf("%d\n", users[i].ff_cnt);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:45:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &num_user, &num_group);
     ^
./Main.c:51:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &a, &b);
         ^