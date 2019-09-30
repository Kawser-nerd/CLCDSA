child_price, adult_price, discount_price, discount_min = map(int, input().split())
child_num, adult_num = map(int, input().split())

person_sum = child_num + adult_num
print(child_price * child_num + adult_price * adult_num - (discount_price * person_sum if person_sum >= discount_min else 0))