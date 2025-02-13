#include "domye.h"

/*run函数实现底层，如控制页面切换*/
/*flag为一级菜单标志，flag_B为二级菜单标志，标志即为当前页面的第几项*/
/*通过while循环，读取read函数，read函数用来写显示页面*/
/*通过key_read函数，读取按键，然后加或减菜单标志，然后因为处在循环中，会不断调用read函数*/

uint16_t flag_C = 1;
int led_num = 0;
int led_state[7] = {0};
int no = 1;
uint16_t led_all = 1;

/*主界面函数，即控制主菜单的功能*/
/*flag为当前菜单的标志*/
void run_A(int flag)
{
    while (1)
    {
        int key_value = key_read();
        if (key_value == 1)
        {
            flag--;
            if (flag == 0)
                flag = 4;
        }
        if (key_value == 3)
        {
            flag++;
            if (flag == 5)
                flag = 1;
        }

        if (key_value == 2)
        {
            run_B(flag, 1); // 如果按下2键，则进入对应的二级菜单函数
        }
        read_A(flag); // 显示当前页面
    }
}

/*二级菜单函数，此函数控制页面的切换，而非具体的功能*/
/*flag为第一级菜单的标志，判断当前为哪一个主菜单的二级菜单*/
/*flag_B为当前菜单标志，即当前为第二菜单的第几项*/
void run_B(int flag, int flag_B)
{
    if (flag == 1) // 如果为第一个一级菜单，则进入对应的二级菜单函数
    {
        run_B_1(flag, flag_B);
    }
    if (flag == 2)
    {
        while (1)
        {
            int key_value = key_read();
            read_B_2(flag_B);
            if (key_value == 1)
            {
                flag_B--;
                if (flag_B == 0)
                    flag_B = 4;
            }
            if (key_value == 3)
            {
                flag_B++;
                if (flag_B == 5)
                    flag_B = 1;
            }
            if (key_value == 2)
            {
                if (flag_B == 4)
                    run_A(flag);
                else
                    run_C(flag, flag_B);
            }
        }
    }
    if (flag == 3)
    {
        while (1)
        {
            int key_value = key_read();
            read_B_3(flag_B);
            if (key_value == 1)
            {
                flag_B--;
                if (flag_B == 0)
                    flag_B = 4;
            }
            if (key_value == 3)
            {
                flag_B++;
                if (flag_B == 5)
                    flag_B = 1;
            }
            if (key_value == 2)
            {
                if (flag_B == 4)
                    run_A(flag);
                else
                    run_C(flag, flag_B);
            }
        }
    }
}

/*三级菜单函数，即控制三级菜单的功能*/
/*flag为第一级菜单的标志，判断当前为哪一个主菜单的二级菜单*/
/*flag_B为当前菜单标志，即当前为第二菜单的第几项功能*/
void run_C(int flag, int flag_B) // flag为一级菜单标志，flag_B为二级菜单标志
{
    /*第一个一级菜单*/
    if (flag == 1)
    {
        /*第一个一级菜单的第一个二      级菜单*/
        if (flag_B == 1)
        {
            led_init();
            led_all_off();
            for (int i = 0; i < 8; i++)
            {
                led(i, ENABLE);
                delay(100);
                led(i, DISABLE);
            }
        }

        /*第一个一级菜单的第二个二级菜单*/
        if (flag_B == 2)
        {
            led_init();
            led_all_off();
            for (int i = 7; i >= 0; i--)
            {
                led(i, ENABLE);
                delay(100);
                led(i, DISABLE);
            }
        }

        /*第一个一级菜单的第三个二级菜单*/
        if (flag_B == 3)
        {
            led_init();
            if (led_all == 1)
            {
                led_all_on();
                led_all = 0;
            }
            else
            {
                led_all_off();
                led_all = 1;
            }
        }
        if (flag_B == 4)
        {
            run_B_1_4(1);
        }
        if (flag_B == 5)
        {
            run_A(flag);
        }
    }

    /*第二个一级菜单*/
    if (flag == 2)
    {
        run_B_2(flag_B);
    }

    /*第三个一级菜单*/
    if (flag == 3)
    {
        switch (flag_B)
        {
        case 1:
            key_B_init();
            run_count(0, 0);
        case 2:
            run_B_3_2(1);
        }
    }
}

void run_B_1_4(int flag_C)
{
    led_init();
    if (no == 1)
    {
        led_all_off();
        no++;
    }

    while (1)
    {
        read_B_1_4(flag_C, led_num, led_state);
        int key_value = key_read();
        if (key_value == 1)
        {
            flag_C--;
            if (flag_C == 0)
                flag_C = 4;
        }
        if (key_value == 3)
        {
            flag_C++;
            if (flag_C == 5)
                flag_C = 1;
        }

        if (key_value == 2)
        {
            if (flag_C == 1) //
            {
                OLED_ReverseArea(16, 37, 8, 16);
                OLED_Update();
                delay(200);
                OLED_ReverseArea(16, 37, 8, 16);
                OLED_Update();
                delay(200);
                while (1)
                {
                    key_value = key_read();

                    if (key_value == 2)
                    {
                        led_num++;
                        if (led_num == 8)
                            led_num = 0;
                    }
                    led_num_read(led_num);
                    if (key_value == 1)
                    {
                        flag_C--;
                        if (flag_C == 0)
                            flag_C = 3;
                        run_B_1_4(flag_C);
                    }
                    if (key_value == 3)
                    {
                        flag_C++;
                        if (flag_C == 4)
                            flag_C = 1;
                        run_B_1_4(flag_C);
                    }
                }
            }
            if (flag_C == 2)
            {
                OLED_ReverseArea(55, 37, 16, 16);
                OLED_Update();
                delay(200);
                OLED_ReverseArea(55, 37, 16, 16);
                OLED_Update();
                delay(200);
                while (1)
                {
                    key_value = key_read();

                    if (key_value == 2)
                    {
                        if (led_state[led_num] == 0)
                        {
                            led(led_num, ENABLE);
                            led_state[led_num] = 1;
                        }
                        else
                        {
                            led(led_num, DISABLE);
                            led_state[led_num] = 0;
                        }
                    }
                    if (key_value == 1)
                    {
                        flag_C--;
                        if (flag_C == 0)
                            flag_C = 3;
                        run_B_1_4(flag_C);
                    }
                    if (key_value == 3)
                    {
                        flag_C++;
                        if (flag_C == 4)
                            flag_C = 1;
                        run_B_1_4(flag_C);
                    }
                    led_state_read(led_num, led_state);
                }
            }
            if (flag_C == 3)
            {
                for (int i = 0; i <= 7; i++)
                {
                    led_state[i] = 0;
                }
                led_all_off();
            }
            if (flag_C == 4)
            {
                led_num = 0;
                run_B(1, 4);
            }
        }
    }
}

void run_B_1(int flag, int flag_B)
{
    while (1)
    {
        int key_value = key_read();
        read_B_1(flag_B);
        if (key_value == 1)
        {
            flag_B--;
            if (flag_B == 0)
                flag_B = 5;
        }
        if (key_value == 3)
        {
            flag_B++;
            if (flag_B == 6)
                flag_B = 1;
        }
        if (key_value == 2)
        {
            if (flag_B == 6)
                run_A(flag); // 返回主菜单
            else
                run_C(flag, flag_B);
        }
    }
}

void run_B_2(int num)
{
    while (1)
    {
        int key_value = key_read();
        if (num == 1)
        {
            OLED_Clear();
            OLED_ShowImage(37, 5, 50, 50, zuoquan);
            OLED_Update();
            if (key_value == 2)
                run_B(2, 1);
        }
        else if (num == 3)
        {
            while (1)
            {
                key_value = key_read();
                if (key_value == 2)
                    run_B(2, 3);
                if (key_value == 1)
                {
                    num--;
                    if (num == 0)
                        num = 3;
                    run_B_2(num);
                }
                if (key_value == 3)
                {
                    num++;
                    if (num == 4)
                        num = 1;
                    run_B_2(num);
                }
                OLED_Clear();
                OLED_ShowImage(37, 5, 50, 50, zuoquan);
                OLED_Update();
                delay(300);
                key_value = key_read();
                if (key_value == 2)
                    run_B(2, 3);
                if (key_value == 1)
                {
                    num--;
                    if (num == 0)
                        num = 3;
                    run_B_2(num);
                }
                if (key_value == 3)
                {
                    num++;
                    if (num == 4)
                        num = 1;
                    run_B_2(num);
                }
                OLED_Clear();
                OLED_ShowImage(37, 5, 50, 50, youquan);
                OLED_Update();
                delay(300);
            }
        }

        else if (num == 2)
        {
            OLED_Clear();
            OLED_ShowImage(33, 0, 60, 60, ahut);
            OLED_Update();
            if (key_value == 2)
                run_B(2, 2);
        }
        if (key_value == 2)
            break;
        if (key_value == 1)
        {
            num--;
            if (num == 0)
                num = 3;
        }
        if (key_value == 3)
        {
            num++;
            if (num == 4)
                num = 1;
        }
    }
}

void run_count(double shangyige, double fuhao)
{
    int cishu = 0;
    double tmp;
    double result = 0;
    double num_1 = 0;
    int xiaoshu = 0;
    int no = 0;
    int linshi;
    int weishu = 0;
    while (1)
    {
        read_count(shangyige, fuhao, num_1, result);

        int back = key_read();
        if (back == 2)
        {
            result = 0;
            run_B(3, 1);
        }
        double key_value = key_B_read();
        int key_value_int = (int)key_value;

        if (key_value == 41 && no == 0)
        {
            xiaoshu = 1;
            no = 1;
        }

        if (key_value_int > 0 && key_value_int / 10 < 4 && key_value_int % 10 <= 3)
        {
            switch (key_value_int / 10)
            {
            case 1:
                weishu = 10;
                break;
            case 2:
                weishu = 17;
                break;
            case 3:
                weishu = 24;
                break;
            }

            switch (xiaoshu)
            {
            case 0:
                tmp = key_value - weishu;
                num_1 = num_1 * 10 + tmp;
                break;
            case 1:
                tmp = (key_value - weishu) / 10;
                num_1 = num_1 + tmp;
                xiaoshu++;
                break;
            case 2:
                tmp = (key_value - weishu) / 100;
                num_1 = num_1 + tmp;
                xiaoshu = 3;
                break;
            }
        }

        if (key_value == 42)
        {
            if (xiaoshu == 1)
                xiaoshu++;
            else if (xiaoshu == 2)
                xiaoshu++;
            else if (xiaoshu == 0)
                num_1 = num_1 * 10;
        }

        if (key_value == 14 || key_value == 24 || key_value == 34 || key_value == 44)
        {
            if (cishu != 0)
                num_1 = result;

            run_count(num_1, key_value);
        }

        if (key_value == 43)
        {
            if (fuhao == 14)
            {
                result = num_1 + shangyige;
            }
            if (fuhao == 24)
            {
                result = shangyige - num_1;
            }
            if (fuhao == 34)
            {
                result = num_1 * shangyige;
            }
            if (fuhao == 44)
            {
                if (num_1 == 0)
                    run_count(shangyige, 0);
                else
                    result = shangyige / num_1;
            }
            cishu = 1;
        }
        if (back == 3)
            run_count(0, 0);
        if (back == 1)
        {
            switch (xiaoshu)
            {
            case 0:
                num_1 = (int)num_1 / 10;
                break;
            case 1:
                xiaoshu = 0;
                no = 0;
                break;
            case 2:
                linshi = num_1 * 10 / 10;
                num_1 = (double)linshi;
                xiaoshu = 1;
                break;
            case 3:
                linshi = num_1 * 100 / 10;
                num_1 = (double)linshi / 10;
                xiaoshu = 2;
                break;
            }
        }
    }
}

void run_B_3_2(int flag_C)
{
    int guang = 0;
    int re = 0;
    led_init();
    led_all_off();
    key_A_init();
    beep_init();
    ad_init();
    while (1)
    {
        read_B_3_2(flag_C, guang, re);
        int key_value = key_read();
        if (key_value == 1)
        {
            flag_C--;
            if (flag_C == 0)
                flag_C = 3;
        }
        if (key_value == 3)
        {
            flag_C++;
            if (flag_C == 4)
                flag_C = 1;
        }
        if (key_value == 2)
        {
            if (flag_C == 3)
            {
                DMA_Cmd(DMA1_Channel1, DISABLE);
                ADC_DMACmd(ADC1, DISABLE);
                ADC_Cmd(ADC1, DISABLE);
                run_B(3, 2);
            }
            if (flag_C == 1)
            {
                guang = guang ? 0 : 1;
            }
            if (flag_C == 2)
            {
                re = re ? 0 : 1;
            }
        }
        if (guang == 1)
        {
            double guang_ya = (double)AD_Value[1] / 4095 * 3.3;
            if (guang_ya >= 3.1)
                led_all_on();
            else
                led_all_off();
        }
        if (re == 1)
        {
            double RE_ya = (double)AD_Value[0] / 4095 * 3.3;
            if (RE_ya <= 1.9)
                beep(1000, 500);
        }
    }
}

int countDigits(int n)
{
    if (n == 0)
    {
        return 1; // 0的位数是1
    }

    int count = 0;
    // 忽略数字的符号，只计算绝对值的位数
    n = (n < 0) ? -n : n;

    while (n > 0)
    {
        count++;
        n /= 10;
    }

    return count;
}