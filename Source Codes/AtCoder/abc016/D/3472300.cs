using System;
using System.Linq;//??????
using System.Collections.Generic;
class Program
{
	static void Main()
	{
		string[] input = Console.ReadLine().Split(' ');
    Vector2 PointA = new Vector2(decimal.Parse(input[0]), decimal.Parse(input[1]));
    Vector2 PointB = new Vector2(decimal.Parse(input[2]), decimal.Parse(input[3]));
    long answer = 0;

    long n = long.Parse(Console.ReadLine());

    Vector2[] vecs = new Vector2[n+1];
    
    for(long i = 0; i < n; i++)
    {
      string[] inputv = Console.ReadLine().Split(' ');
      vecs[i] = new Vector2(decimal.Parse(inputv[0]), decimal.Parse(inputv[1]));
    }
    vecs[n] = vecs[0];
    
    for(long i = 0; i < n; i++)
    {
      answer += Vector2.IsIntersect(PointA, PointB, vecs[i], vecs[i+1]);
    }

    Console.WriteLine(1+answer/2);//??????
	}
}

class Vector2//2??????
{
static decimal EPS = 1e-10m;//??????

  public Vector2 (decimal X, decimal Y)
  {
    this.x = X;
    this.y = Y;
  }

  public decimal x {private set; get;}
  public decimal y {private set; get;}

  public static Vector2 operator + (Vector2 ob1, Vector2 ob2)//?????????
  {
    return new Vector2 (ob1.x + ob2.x, ob1.y + ob2.y);
  }
  public static Vector2 operator - (Vector2 ob1, Vector2 ob2)
  {
    return new Vector2 (ob1.x - ob2.x, ob1.y - ob2.y);
  }
  public static Vector2 operator * (Vector2 ob, decimal scalar)
  {
    return new Vector2 (ob.x * scalar, ob.y * scalar);
  }
  public static Vector2 operator * (decimal scalar, Vector2 ob)
  {
    return new Vector2 (ob.x * scalar, ob.y * scalar);
  }
  public static Vector2 operator / (Vector2 ob, decimal scalar)
  {
    return new Vector2 (ob.x / scalar, ob.y / scalar);
  }

  public decimal Length()//????????2?
  {
    return x * x + y * y;
  }
  public static decimal Distance(Vector2 ob1, Vector2 ob2)//2?????
  {
    return (decimal)Math.Sqrt((double)((ob1.x-ob2.x) * (ob1.x-ob2.x) + (ob1.y-ob2.y) * (ob1.y-ob2.y)));
  }
  public static decimal DotProduct(Vector2 ob1, Vector2 ob2)//??
  {
    return ob1.x * ob2.x + ob1.y * ob2.y;
  }
  public static decimal CrossProduct(Vector2 ob1, Vector2 ob2)//????2????????????
  {
    return ob1.x * ob2.y - ob1.y * ob2.x;
  }
  public static decimal Arg(Vector2 p)//x???????
  {
    return (decimal)Math.Atan2((double)p.y, (double)p.x);
  }
  public static Vector2 PoralCoordinate(decimal radius, decimal angle)//?????????????
  {
    return new Vector2(radius * (decimal)Math.Cos((double)angle), radius * (decimal)Math.Sin((double)angle));
  }

  public static Vector2 Projection(Vector2 beginPoint, Vector2 endPoint, Vector2 point)//????
  {
    Vector2 segment = endPoint - beginPoint;
    decimal ratio = Vector2.DotProduct(point - beginPoint, segment) / segment.Length();
    return beginPoint + segment * ratio;//?????
  }

public static long WhereVector(Vector2 beginPoint, Vector2 endPoint, Vector2 point)
  {//????????????
    Vector2 segment = endPoint - beginPoint;
    Vector2 aimVec = point - beginPoint;
    if(Vector2.CrossProduct(segment, aimVec) > EPS)
      return 1;//??????
    else if(Vector2.CrossProduct(segment, aimVec) < -EPS)
      return 2;//?????
    else if(Vector2.DotProduct(segment, aimVec) < -1+EPS)
      return 3;//??????????
    else if(segment.Length() < aimVec.Length())
      return 4;//????????
    else
      return 5;//?????
  }

  public static long IsIntersect(Vector2 vecA, Vector2 vecB,
    Vector2 vecAsub, Vector2 vecBsub)//2???????
  {
    bool answer = false;

    if(Vector2.WhereVector(vecA, vecB, vecAsub) + Vector2.WhereVector(vecA, vecB, vecBsub) == 3
    && Vector2.WhereVector(vecAsub, vecBsub, vecA) + Vector2.WhereVector(vecAsub, vecBsub, vecB) == 3)
      answer = true;
    if(Vector2.WhereVector(vecA, vecB, vecAsub) == 5 || Vector2.WhereVector(vecA, vecB, vecBsub) == 5
    || Vector2.WhereVector(vecAsub, vecBsub, vecA) == 5 || Vector2.WhereVector(vecAsub, vecBsub, vecB) == 5)
      answer = true;
    return((answer) ? 1 : 0);
  }

  public static Vector2 IntersectPoint(Vector2 vecA, Vector2 vecB, 
    Vector2 vecAsub, Vector2 vecBsub)//2?????
  {
    Vector2 leftPoint = Vector2.Projection(vecA, vecB, vecAsub);//????????
    Vector2 rightPoint = Vector2.Projection(vecA, vecB, vecBsub);//????????
    decimal leftLength = (vecAsub - leftPoint).Length();
    decimal rightLength = (vecBsub - rightPoint).Length();

    leftLength = (decimal)(Math.Sqrt((double)leftLength));
    rightLength = (decimal)(Math.Sqrt((double)rightLength));
    
    if(leftLength < EPS) return leftPoint;
    else if(rightLength < EPS) return rightPoint;
    decimal ratio = leftLength / (leftLength + rightLength);
    return (leftPoint + ratio * (rightPoint - leftPoint));
  }

public static Vector2[] circleLineIntersection(Vector2 centerPoint, decimal circleRadius, 
    Vector2 beginPoint, Vector2 endPoint)//???????
  {
    Vector2[] answers = new Vector2[2];
    Vector2 segment = endPoint - beginPoint;
    Vector2 unitSegment = segment / (decimal)Math.Sqrt((double)segment.Length());
    Vector2 circleProjection = Projection(beginPoint, endPoint, centerPoint);//?????
    decimal lineLength = 
      (decimal)Math.Sqrt((double)(circleRadius*circleRadius - (circleProjection-centerPoint).Length()));//????????
    //Console.WriteLine(unitSegment.x+" "+unitSegment.y);
    answers[0] = circleProjection + (unitSegment * lineLength);
    answers[1] = circleProjection - (unitSegment * lineLength);
    return answers;
  }

  public static Vector2[] CircleIntersection(Vector2 centerPointA, decimal circleRadiusA, 
      Vector2 centerPointB, decimal circleRadiusB)//2????
    {
      Vector2[] answers = new Vector2[2];
      decimal centerDistance = Distance(centerPointA, centerPointB);//2???????
      decimal centerAngle = Arg(centerPointB - centerPointA);
      decimal intersectionAngle = (decimal)Math.Acos((double)(circleRadiusA*circleRadiusA
        + centerDistance*centerDistance - circleRadiusB*circleRadiusB)
        /(double)(2*circleRadiusA*centerDistance));//????
      answers[0] = centerPointA + PoralCoordinate(circleRadiusA, centerAngle+intersectionAngle);
      answers[1] = centerPointA + PoralCoordinate(circleRadiusA, centerAngle-intersectionAngle); 
      if(answers[0].x > answers[1].x || (Math.Abs(answers[0].x - answers[1].x) < EPS && answers[0].y > answers[1].y))
      {
        Vector2 swapMemo = answers[0];
        answers[0] = answers[1];
        answers[1] = swapMemo;
      }
      return answers; 
    }

    public static decimal TriangleAria(Vector2 PointA, Vector2 PointB, Vector2 PointC)//3????????????
    {
      decimal a = PointB.x - PointA.x;
      decimal b = PointB.y - PointA.y;
      decimal c = PointC.x - PointA.x;
      decimal d = PointC.y - PointA.y;
      return (Math.Abs(a*d-b*c)) / 2;
    }
}