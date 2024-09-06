def main():
    dollars = get_input()
    amount = get_coins(dollars)
    print(amount)

def get_input():
    # Prompts user for a positive float and returns that amount in cents as an integer.
    while True:
        try:
            dollars = float(input("Change owed: "))
            if dollars > 0:
                return int(round(dollars * 100))  # Use round to handle floating-point precision issues
        except ValueError:
            print("Invalid input. Please enter a number.")

def get_coins(cents):
    # Returns the smallest number of coins that can be given for the change owed.
    counter = 0
    for coin in [25, 10, 5, 1]:
        counter += cents // coin  # Use integer division to determine how many coins of this type
        cents %= coin  # Update the remaining cents
    return counter

if __name__ == "__main__":
    main()
