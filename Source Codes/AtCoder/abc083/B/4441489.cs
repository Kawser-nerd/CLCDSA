public class Hello{
    public static void Main(){

        string[] str = System.Console.ReadLine().Split(' ');
        int N = int.Parse(str[0]);
        int A = int.Parse(str[1]);
        int B = int.Parse(str[2]);

        int ans = 0;
        for(int i = 1; i <= N; i++){
            //??i????????
            int tmp = i;
            int sum = 0;
            while(tmp > 0){
                sum += tmp % 10;
                tmp /= 10;
            }
          	//??i??????A??B???????
            if(sum >= A && sum <= B) ans += i;
        }
        System.Console.WriteLine(ans);
    }
}