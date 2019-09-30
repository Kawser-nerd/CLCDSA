// ConsoleApplication1.cpp : ????? ????????????? ???????????
//

#include <iostream>
#include <memory>


int main()
{
	bool n = false, s = false, w = false, e = false;
	while(int c = std::cin.get())
	{
		if (c == EOF)break;
		switch (c)
		{
		case 'N':
			n = true;
			break;
		case 'S':
			s = true;
			break;
		case 'W':
			w = true;
			break;
		case 'E':
			e = true;
			break;
		}
	}

	if (n && s && !e && !w || n && s && e && w || !n && !s && e & w || !n && !s && !w && !e)
	{
		std::cout << "Yes";
	}
	else
	{
		std::cout << "No";
	}

    return 0;
} ./Main.cpp:31:19: warning: '&&' within '||' [-Wlogical-op-parentheses]
        if (n && s && !e && !w || n && s && e && w || !n && !s && e & w || !n && !s && !w && !e)
            ~~~~~~~~~~~~~^~~~~ ~~
./Main.cpp:31:19: note: place parentheses around the '&&' expression to silence this warning
        if (n && s && !e && !w || n && s && e && w || !n && !s && e & w || !n && !s && !w && !e)
                         ^
            (                 )
./Main.cpp:31:40: warning: '&&' within '||' [-Wlogical-op-parentheses]
        if (n && s && !e && !w || n && s && e && w || !n && !s && e & w || !n && !s && !w && !e)
                               ~~ ~~~~~~~~~~~~^~~~
./Main.cpp:31:40: note: place parentheses around the '&&' expression to silence this warning
        if (n && s && !e && !w || n && s && e && w || !n && !s && e & w || !n && !s && !w && !e)
                                              ^
                                  (               )
./Main.cpp:31:57: warning: '&&' within '||' [-Wlogical-op-parent...