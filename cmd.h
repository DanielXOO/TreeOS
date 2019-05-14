extern void out(char *str);
extern void NEXTL(int type);
extern void clean_mas(void);
extern void proper(void);
extern void Fboot(void);
int checker(char input[128],char command[128]){
    int i = 0;
    int answ;
    while(i < 128){
        if (input[i] != command[i]){
            answ = 0;
            break;
        }
        else
        {
            answ = 1;
        }
        i++;
    }
    return answ;
}
extern void power_down(void);
void operation(char cmd[128]){
    char powerdown[128] = {"powerdown"};
    char cleanscr[128] = {"clean"};
    if (checker(cmd,powerdown)) {
        power_down();
    }
    if (checker(cmd,cleanscr)){
        proper();
        Fboot();
    }
    else{
        NEXTL(0);
        out("Error: Command not found");
        NEXTL(1);
    }
    clean_mas();    
}