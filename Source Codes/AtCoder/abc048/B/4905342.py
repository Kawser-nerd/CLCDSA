a,b,x =map( int, input().split() )

cnt = 0

start  = ( a - 1) // x
end = b// x 

print(end - start)