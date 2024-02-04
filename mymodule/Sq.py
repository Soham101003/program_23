def calculate_square(limit):
    squares=[i**2 for i in range(1,limit+1)]
    return squares
def main():
    try:
        limit=int(input("Please enter a number as input"))
        if limit<0:
            print("Please enter a positive number")
        else:
            result=calculate_square(limit)
            print(f"Squares upto the limit is:{result}")
    except ValueError:
        print("Invalid Input")
if __name__=='__main__':
    main()
