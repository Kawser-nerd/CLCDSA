using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        //????
        //????????????m/s(m)
        int k = int.Parse(Console.ReadLine());
        long[] res = solve(k);
        Console.WriteLine(string.Join("\n", res));
    }
    static long[] solve(int k)
    {
        long[] res = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 19, 29, 39, 49, 59, 69, 79, 89, 99, 199, 299, 399, 499, 599, 699, 799, 899, 999, 1099, 1199, 1299, 1399, 1499, 1599, 1699, 1799, 1899, 1999, 2999, 3999, 4999, 5999, 6999, 7999, 8999, 9999, 10999, 11999, 12999, 13999, 14999, 15999, 16999, 17999, 18999, 19999, 20999, 21999, 22999, 23999, 24999, 25999, 26999, 27999, 28999, 29999, 39999, 49999, 59999, 69999, 79999, 89999, 99999, 109999, 119999, 129999, 139999, 149999, 159999, 169999, 179999, 189999, 199999, 209999, 219999, 229999, 239999, 249999, 259999, 269999, 279999, 289999, 299999, 309999, 319999, 329999, 339999, 349999, 359999, 369999, 379999, 389999, 399999, 499999, 599999, 699999, 799999, 899999, 999999, 1099999, 1199999, 1299999, 1399999, 1499999, 1599999, 1699999, 1799999, 1899999, 1999999, 2099999, 2199999, 2299999, 2399999, 2499999, 2599999, 2699999, 2799999, 2899999, 2999999, 3099999, 3199999, 3299999, 3399999, 3499999, 3599999, 3699999, 3799999, 3899999, 3999999, 4099999, 4199999, 4299999, 4399999, 4499999, 4599999, 4699999, 4799999, 4899999, 4999999, 5999999, 6999999, 7999999, 8999999, 9999999, 10999999, 11999999, 12999999, 13999999, 14999999, 15999999, 16999999, 17999999, 18999999, 19999999, 20999999, 21999999, 22999999, 23999999, 24999999, 25999999, 26999999, 27999999, 28999999, 29999999, 30999999, 31999999, 32999999, 33999999, 34999999, 35999999, 36999999, 37999999, 38999999, 39999999, 40999999, 41999999, 42999999, 43999999, 44999999, 45999999, 46999999, 47999999, 48999999, 49999999, 50999999, 51999999, 52999999, 53999999, 54999999, 55999999, 56999999, 57999999, 58999999, 59999999, 69999999, 79999999, 89999999, 99999999, 109999999, 119999999, 129999999, 139999999, 149999999, 159999999, 169999999, 179999999, 189999999, 199999999, 209999999, 219999999, 229999999, 239999999, 249999999, 259999999, 269999999, 279999999, 289999999, 299999999, 309999999, 319999999, 329999999, 339999999, 349999999, 359999999, 369999999, 379999999, 389999999, 399999999, 409999999, 419999999, 429999999, 439999999, 449999999, 459999999, 469999999, 479999999, 489999999, 499999999, 509999999, 519999999, 529999999, 539999999, 549999999, 559999999, 569999999, 579999999, 589999999, 599999999, 609999999, 619999999, 629999999, 639999999, 649999999, 659999999, 669999999, 679999999, 689999999, 699999999, 799999999, 899999999, 999999999, 1099999999, 1199999999, 1299999999, 1399999999, 1499999999, 1599999999, 1699999999, 1799999999, 1899999999, 1999999999, 2099999999, 2199999999, 2299999999, 2399999999, 2499999999, 2599999999, 2699999999, 2799999999, 2899999999, 2999999999, 3099999999, 3199999999, 3299999999, 3399999999, 3499999999, 3599999999, 3699999999, 3799999999, 3899999999, 3999999999, 4099999999, 4199999999, 4299999999, 4399999999, 4499999999, 4599999999, 4699999999, 4799999999, 4899999999, 4999999999, 5099999999, 5199999999, 5299999999, 5399999999, 5499999999, 5599999999, 5699999999, 5799999999, 5899999999, 5999999999, 6099999999, 6199999999, 6299999999, 6399999999, 6499999999, 6599999999, 6699999999, 6799999999, 6899999999, 6999999999, 7099999999, 7199999999, 7299999999, 7399999999, 7499999999, 7599999999, 7699999999, 7799999999, 7899999999, 7999999999, 8999999999, 9999999999, 10999999999, 11999999999, 12999999999, 13999999999, 14999999999, 15999999999, 16999999999, 17999999999, 18999999999, 19999999999, 20999999999, 21999999999, 22999999999, 23999999999, 24999999999, 25999999999, 26999999999, 27999999999, 28999999999, 29999999999, 30999999999, 31999999999, 32999999999, 33999999999, 34999999999, 35999999999, 36999999999, 37999999999, 38999999999, 39999999999, 40999999999, 41999999999, 42999999999, 43999999999, 44999999999, 45999999999, 46999999999, 47999999999, 48999999999, 49999999999, 50999999999, 51999999999, 52999999999, 53999999999, 54999999999, 55999999999, 56999999999, 57999999999, 58999999999, 59999999999, 60999999999, 61999999999, 62999999999, 63999999999, 64999999999, 65999999999, 66999999999, 67999999999, 68999999999, 69999999999, 70999999999, 71999999999, 72999999999, 73999999999, 74999999999, 75999999999, 76999999999, 77999999999, 78999999999, 79999999999, 80999999999, 81999999999, 82999999999, 83999999999, 84999999999, 85999999999, 86999999999, 87999999999, 88999999999, 89999999999, 99999999999, 109999999999, 119999999999, 129999999999, 139999999999, 149999999999, 159999999999, 169999999999, 179999999999, 189999999999, 199999999999, 209999999999, 219999999999, 229999999999, 239999999999, 249999999999, 259999999999, 269999999999, 279999999999, 289999999999, 299999999999, 309999999999, 319999999999, 329999999999, 339999999999, 349999999999, 359999999999, 369999999999, 379999999999, 389999999999, 399999999999, 409999999999, 419999999999, 429999999999, 439999999999, 449999999999, 459999999999, 469999999999, 479999999999, 489999999999, 499999999999, 509999999999, 519999999999, 529999999999, 539999999999, 549999999999, 559999999999, 569999999999, 579999999999, 589999999999, 599999999999, 609999999999, 619999999999, 629999999999, 639999999999, 649999999999, 659999999999, 669999999999, 679999999999, 689999999999, 699999999999, 709999999999, 719999999999, 729999999999, 739999999999, 749999999999, 759999999999, 769999999999, 779999999999, 789999999999, 799999999999, 809999999999, 819999999999, 829999999999, 839999999999, 849999999999, 859999999999, 869999999999, 879999999999, 889999999999, 899999999999, 909999999999, 919999999999, 929999999999, 939999999999, 949999999999, 959999999999, 969999999999, 979999999999, 989999999999, 999999999999, 1099999999999, 1199999999999, 1299999999999, 1399999999999, 1499999999999, 1599999999999, 1699999999999, 1799999999999, 1899999999999, 1999999999999, 2099999999999, 2199999999999, 2299999999999, 2399999999999, 2499999999999, 2599999999999, 2699999999999, 2799999999999, 2899999999999, 2999999999999, 3099999999999, 3199999999999, 3299999999999, 3399999999999, 3499999999999, 3599999999999, 3699999999999, 3799999999999, 3899999999999, 3999999999999, 4099999999999, 4199999999999, 4299999999999, 4399999999999, 4499999999999, 4599999999999, 4699999999999, 4799999999999, 4899999999999, 4999999999999, 5099999999999, 5199999999999, 5299999999999, 5399999999999, 5499999999999, 5599999999999, 5699999999999, 5799999999999, 5899999999999, 5999999999999, 6099999999999, 6199999999999, 6299999999999, 6399999999999, 6499999999999, 6599999999999, 6699999999999, 6799999999999, 6899999999999, 6999999999999, 7099999999999, 7199999999999, 7299999999999, 7399999999999, 7499999999999, 7599999999999, 7699999999999, 7799999999999, 7899999999999, 7999999999999, 8099999999999, 8199999999999, 8299999999999, 8399999999999, 8499999999999, 8599999999999, 8699999999999, 8799999999999, 8899999999999, 8999999999999, 9099999999999, 9199999999999, 9299999999999, 9399999999999, 9499999999999, 9599999999999, 9699999999999, 9799999999999, 9899999999999, 9999999999999, 10999999999999, 11999999999999, 12999999999999, 13999999999999, 14999999999999, 15999999999999, 16999999999999, 17999999999999, 18999999999999, 19999999999999, 20999999999999, 21999999999999, 22999999999999, 23999999999999, 24999999999999, 25999999999999, 26999999999999, 27999999999999, 28999999999999, 29999999999999, 30999999999999, 31999999999999, 32999999999999, 33999999999999, 34999999999999, 35999999999999, 36999999999999, 37999999999999, 38999999999999, 39999999999999, 40999999999999, 41999999999999, 42999999999999, 43999999999999, 44999999999999, 45999999999999, 46999999999999, 47999999999999, 48999999999999, 49999999999999, 50999999999999, 51999999999999, 52999999999999, 53999999999999, 54999999999999, 55999999999999, 56999999999999, 57999999999999, 58999999999999, 59999999999999, 60999999999999, 61999999999999, 62999999999999, 63999999999999, 64999999999999, 65999999999999, 66999999999999, 67999999999999, 68999999999999, 69999999999999, 70999999999999, 71999999999999, 72999999999999, 73999999999999, 74999999999999, 75999999999999, 76999999999999, 77999999999999, 78999999999999, 79999999999999, 80999999999999, 81999999999999, 82999999999999, 83999999999999, 84999999999999, 85999999999999, 86999999999999, 87999999999999, 88999999999999, 89999999999999, 90999999999999, 91999999999999, 92999999999999, 93999999999999, 94999999999999, 95999999999999, 96999999999999, 97999999999999, 98999999999999, 99999999999999, 100999999999999, 101999999999999, 102999999999999, 103999999999999, 104999999999999, 105999999999999, 106999999999999, 107999999999999, 108999999999999, 109999999999999, 119999999999999, 129999999999999, 139999999999999, 149999999999999, 159999999999999, 169999999999999, 179999999999999, 189999999999999, 199999999999999, 209999999999999, 219999999999999, 229999999999999, 239999999999999, 249999999999999, 259999999999999, 269999999999999, 279999999999999, 289999999999999, 299999999999999, 309999999999999, 319999999999999, 329999999999999, 339999999999999, 349999999999999, 359999999999999, 369999999999999, 379999999999999, 389999999999999, 399999999999999, 409999999999999, 419999999999999, 429999999999999, 439999999999999, 449999999999999, 459999999999999, 469999999999999, 479999999999999, 489999999999999, 499999999999999, 509999999999999, 519999999999999, 529999999999999, 539999999999999, 549999999999999, 559999999999999, 569999999999999, 579999999999999, 589999999999999, 599999999999999, 609999999999999, 619999999999999, 629999999999999, 639999999999999, 649999999999999, 659999999999999, 669999999999999, 679999999999999, 689999999999999, 699999999999999, 709999999999999, 719999999999999, 729999999999999, 739999999999999, 749999999999999, 759999999999999, 769999999999999, 779999999999999, 789999999999999, 799999999999999, 809999999999999, 819999999999999, 829999999999999, 839999999999999, 849999999999999, 859999999999999, 869999999999999, 879999999999999, 889999999999999, 899999999999999, 909999999999999, 919999999999999, 929999999999999, 939999999999999, 949999999999999, 959999999999999, 969999999999999, 979999999999999, 989999999999999, 999999999999999, 1009999999999999, 1019999999999999, 1029999999999999, 1039999999999999, 1049999999999999, 1059999999999999, 1069999999999999, 1079999999999999, 1089999999999999, 1099999999999999, 1109999999999999, 1119999999999999, 1129999999999999, 1139999999999999, 1149999999999999, 1159999999999999, 1169999999999999, 1179999999999999, 1189999999999999, 1199999999999999, 1299999999999999, 1399999999999999, 1499999999999999, 1599999999999999, 1699999999999999, 1799999999999999, 1899999999999999, 1999999999999999, 2099999999999999, 2199999999999999, 2299999999999999, 2399999999999999, 2499999999999999, 2599999999999999, 2699999999999999, 2799999999999999, 2899999999999999, 2999999999999999, 3099999999999999, 3199999999999999, 3299999999999999, 3399999999999999, 3499999999999999, 3599999999999999, 3699999999999999, 3799999999999999, 3899999999999999, 3999999999999999, 4099999999999999, 4199999999999999, 4299999999999999, 4399999999999999, 4499999999999999, 4599999999999999, 4699999999999999, 4799999999999999, 4899999999999999, 4999999999999999, 5099999999999999, 5199999999999999, 5299999999999999, 5399999999999999, 5499999999999999, 5599999999999999, 5699999999999999, 5799999999999999, 5899999999999999, 5999999999999999, 6099999999999999, 6199999999999999, 6299999999999999, 6399999999999999, 6499999999999999, 6599999999999999, 6699999999999999, 6799999999999999, 6899999999999999, 6999999999999999, 7099999999999999, 7199999999999999, 7299999999999999, 7399999999999999, 7499999999999999, 7599999999999999, 7699999999999999, 7799999999999999, 7899999999999999, 7999999999999999, 8099999999999999, 8199999999999999, 8299999999999999, 8399999999999999, 8499999999999999, 8599999999999999, 8699999999999999, 8799999999999999, 8899999999999999, 8999999999999999, 9099999999999999, 9199999999999999, 9299999999999999, 9399999999999999, 9499999999999999, 9599999999999999, 9699999999999999, 9799999999999999, 9899999999999999, 9999999999999999, 10099999999999999, 10199999999999999, 10299999999999999, 10399999999999999, 10499999999999999, 10599999999999999, 10699999999999999, 10799999999999999, 10899999999999999, 10999999999999999, 11099999999999999, 11199999999999999, 11299999999999999, 11399999999999999, 11499999999999999, 11599999999999999, 11699999999999999, 11799999999999999, 11899999999999999, 11999999999999999, 12099999999999999, 12199999999999999, 12299999999999999, 12399999999999999, 12499999999999999, 12599999999999999, 12699999999999999, 12799999999999999, 12899999999999999, 12999999999999999, 13999999999999999, 14999999999999999, 15999999999999999, 16999999999999999, 17999999999999999, 18999999999999999, 19999999999999999, 20999999999999999, 21999999999999999, 22999999999999999, 23999999999999999, 24999999999999999, 25999999999999999, 26999999999999999, 27999999999999999, 28999999999999999, 29999999999999999, 30999999999999999, 31999999999999999, 32999999999999999, 33999999999999999, 34999999999999999, 35999999999999999, 36999999999999999, 37999999999999999, 38999999999999999, 39999999999999999, 40999999999999999, 41999999999999999, 42999999999999999, 43999999999999999, 44999999999999999, 45999999999999999, 46999999999999999, 47999999999999999, 48999999999999999, 49999999999999999, 50999999999999999, 51999999999999999, 52999999999999999, 53999999999999999, 54999999999999999, 55999999999999999, 56999999999999999, 57999999999999999, 58999999999999999, 59999999999999999, 60999999999999999, 61999999999999999, 62999999999999999, 63999999999999999, 64999999999999999, 65999999999999999, 66999999999999999, 67999999999999999, 68999999999999999, 69999999999999999, 70999999999999999, 71999999999999999, 72999999999999999, 73999999999999999, 74999999999999999, 75999999999999999, 76999999999999999, 77999999999999999, 78999999999999999, 79999999999999999, 80999999999999999, 81999999999999999, 82999999999999999, 83999999999999999, 84999999999999999, 85999999999999999, 86999999999999999, 87999999999999999, 88999999999999999, 89999999999999999, 90999999999999999, 91999999999999999, 92999999999999999, 93999999999999999, 94999999999999999, 95999999999999999, 96999999999999999, 97999999999999999, 98999999999999999, 99999999999999999, 100999999999999999, 101999999999999999, 102999999999999999, 103999999999999999, 104999999999999999, 105999999999999999, 106999999999999999, 107999999999999999, 108999999999999999, 109999999999999999, 110999999999999999, 111999999999999999, 112999999999999999, 113999999999999999, 114999999999999999, 115999999999999999, 116999999999999999, 117999999999999999, 118999999999999999, 119999999999999999, 120999999999999999, 121999999999999999, 122999999999999999, 123999999999999999, 124999999999999999, 125999999999999999, 126999999999999999, 127999999999999999, 128999999999999999, 129999999999999999, 130999999999999999, 131999999999999999, 132999999999999999, 133999999999999999, 134999999999999999, 135999999999999999, 136999999999999999, 137999999999999999, 138999999999999999, 139999999999999999, 149999999999999999, 159999999999999999, 169999999999999999, 179999999999999999, 189999999999999999, 199999999999999999, 209999999999999999, 219999999999999999, 229999999999999999, 239999999999999999, 249999999999999999, 259999999999999999, 269999999999999999, 279999999999999999, 289999999999999999, 299999999999999999, 309999999999999999, 319999999999999999, 329999999999999999, 339999999999999999, 349999999999999999, 359999999999999999, 369999999999999999, 379999999999999999, 389999999999999999, 399999999999999999, 409999999999999999, 419999999999999999, 429999999999999999, 439999999999999999, 449999999999999999, 459999999999999999, 469999999999999999, 479999999999999999, 489999999999999999, 499999999999999999, 509999999999999999, 519999999999999999, 529999999999999999, 539999999999999999, 549999999999999999, 559999999999999999, 569999999999999999, 579999999999999999, 589999999999999999, 599999999999999999, 609999999999999999, 619999999999999999, 629999999999999999, 639999999999999999, 649999999999999999, 659999999999999999, 669999999999999999, 679999999999999999, 689999999999999999, 699999999999999999, 709999999999999999, 719999999999999999, 729999999999999999, 739999999999999999, 749999999999999999, 759999999999999999, 769999999999999999, 779999999999999999, 789999999999999999, 799999999999999999, 809999999999999999, 819999999999999999, 829999999999999999, 839999999999999999, 849999999999999999, 859999999999999999, 869999999999999999, 879999999999999999, 889999999999999999, 899999999999999999, 909999999999999999, 919999999999999999, 929999999999999999, 939999999999999999, 949999999999999999, 959999999999999999, 969999999999999999, 979999999999999999, 989999999999999999, 999999999999999999 };
        return res.Take(k).ToArray();
        long[] multi = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000, 100000000000000, 1000000000000000, 10000000000000000, 100000000000000000, 1000000000000000000 };
        List<Tuple<long,double>> lis = new List<Tuple<long, double>>();
        //????????????1000???????
        //
        for (int i = 0; i <= 17; i++)
        {
            //??
            long ryuu = multi[Math.Max(0, i - 4)];
            for (long j = multi[i] + ryuu - 1; j < multi[i + 1]; j += ryuu)
            {
                lis.Add(new Tuple<long, double>(j, j / sum(j)));
            }
        }
        List<long> l = new List<long>();
        for (int i = 0; i < lis.Count; i++)
        {
            for (int j = i + 1; j < lis.Count; j++) if (lis[i].Item2 > lis[j].Item2) goto end;
            l.Add(lis[i].Item1);
            end:;
        }
        return l.Take(k).ToArray();
    }
    static double sum(long n)
    {
        long dig;
        double sum = 0;
        while (n > 0)
        {
            dig = n % 10;
            sum += dig;
            n /= 10;
        }
        return sum;
    }
}