#include <stdio.h>
#include <stdlib.h>
#include "linux_list.h"

typedef struct msg_info_t
{
    int msgiId;
    int msgSN;
    float msgVersion;
    struct list_head MsgList;
}msg_info;


int main()
{
    printf("==========this is test begin===========\n");

    msg_info *tmp;
    struct list_head *pos, *q;
    unsigned int loop_num = 10;

    msg_info socket_msg_info;
    INIT_LIST_HEAD(&socket_msg_info.MsgList);

    for(int i = 0; i < loop_num; i++){
        tmp = (msg_info*)malloc(sizeof(msg_info));
        if(tmp == NULL) break;

        tmp->msgiId = i + 1;
        tmp->msgSN = i + 1;
        tmp->msgVersion = 1.0;

        list_add_tail(&(tmp->MsgList), &(socket_msg_info.MsgList));
    }
 
    list_rotate_to_front(&(tmp->MsgList), &(socket_msg_info.MsgList));


    printf("traversing the list using list_for_each()\n");

    list_for_each(pos, &socket_msg_info.MsgList){
        tmp = list_entry(pos, msg_info, MsgList);
        printf("msgID:%d\n", tmp->msgiId);
    }


    printf("==========this is test end===========\n");
    return 0;
}
