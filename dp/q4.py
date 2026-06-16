from datetime import datetime

d1 = datetime.strptime("06-06-2011", "%d-%m-%Y")
d2 = datetime.strptime("06-07-2011", "%d-%m-%Y")

if d1.day == d2.day and ((d1.month % 12) + 1 == d2.month or
                         (d1.month == 12 and d2.month == 1)):
    print("Exactly 1 month apart")
else:
    print("Not exactly 1 month apart")
