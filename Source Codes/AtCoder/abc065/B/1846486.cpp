#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {

    int N;
    std::cin >> N;

    std::vector<int> buttons;
    for(int times = 0 ; times < N ; times++ )
    {
        int button_number;
        std::cin >> button_number;
        /** ??????0????????? **/
        buttons.push_back(button_number - 1);
    }

    std::vector<bool> pushed_button(N);
    int button_index = 0;
    int push_times = 0;

    /** ???????????????????? **/
    while(pushed_button[button_index] == false)
    {
        /** 1????????????????? **/
        if(button_index == 1)
        {
            break;
        }

        push_times++;

        pushed_button[button_index] = true;
        button_index = buttons[button_index];

    }

    std::cout << (button_index == 1 ? push_times : -1) << '\n';

    return 0;
}