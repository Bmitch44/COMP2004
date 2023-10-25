"""This file will test to see if the q2.py file gave the coorrect results"""

def read_input(filename):
    with open(filename) as f:
        content = f.readlines()
    content = [int(x.strip()) for x in content]
    return content

def calc_average(numbers):
    return sum(numbers)/len(numbers)

def calc_minumum(numbers):
    return min(numbers)

def calc_maximum(numbers):
    return max(numbers)

def main():
    numbers = read_input("Assignment-3/input.txt")
    average = calc_average(numbers)
    minimum = calc_minumum(numbers)
    maximum = calc_maximum(numbers)

    print(f"The average value is {int(average)}")
    print(f"The minimum value is {minimum}")
    print(f"The maximum value is {maximum}")


if __name__ == '__main__':
    main()