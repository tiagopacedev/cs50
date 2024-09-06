import csv
import sys


def main():
    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py <database> <sequence>")
        return

    # Read database file into a variable
    database_filename = sys.argv[1]
    with open(database_filename) as db_file:
        reader = csv.DictReader(db_file)
        database = [row for row in reader]

    # Read DNA sequence file into a variable
    sequence_filename = sys.argv[2]
    with open(sequence_filename) as seq_file:
        dna_sequence = seq_file.read().strip()

    # Find longest match of each STR in DNA sequence
    str_counts = {}
    for str_name in reader.fieldnames[1:]:  # Skip the 'name' column
        str_counts[str_name] = longest_match(dna_sequence, str_name)

    # Check database for matching profiles
    for person in database:
        if all(int(person[str_name]) == str_counts[str_name] for str_name in str_counts):
            print(person['name'])
            return

    print("No match")

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""
    longest_run = 0
    subsequence_length = len(subsequence)

    for i in range(len(sequence)):
        count = 0
        while sequence[i + count * subsequence_length:i + (count + 1) * subsequence_length] == subsequence:
            count += 1
        longest_run = max(longest_run, count)

    return longest_run

if __name__ == "__main__":
    main()
