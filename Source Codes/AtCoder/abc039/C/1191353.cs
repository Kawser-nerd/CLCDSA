using System;
class A
{
    static void Main()
    {
        string s = "";   
        string a = Console.ReadLine().Substring(0,12);
        //WBWBWWBWBWBW Do
        //  WBWWBWBWBWWB Re 
        //    WWBWBWBWWBWB Mi
        //     WBWBWBWWBWBW Fa 
        //       WBWBWWBWBWWB So
        //         WBWWBWBWWBWB La
        //           WWBWBWWBWBWB Si
        //            WBWBWWBWBWBW Do
        //            WBWBWWBWBWBW
        if (a == "WBWBWWBWBWBW")
        {
            Console.WriteLine("Do");
        }
        else if (a == "WBWWBWBWBWWB")
        {
            Console.WriteLine("Re");
        }
        else if (a == "WWBWBWBWWBWB")
        {
            Console.WriteLine("Mi");
        }
        else if (a == "WBWBWBWWBWBW")
        {
            Console.WriteLine("Fa");
        }
        else if (a == "WBWBWWBWBWWB")
        {
            Console.WriteLine("So");
        }
        else if (a == "WBWWBWBWWBWB")
        {//            WBWWBWBWWBWB
            Console.WriteLine("La");
        }
        else if (a == "WWBWBWWBWBWB")
        {
            Console.WriteLine("Si");
        }
    }
}