import sys, csv

def main():
    sample_data = []
    found = False

    if len(sys.argv) != 3:
        print("Usage: python3 dna.py people.csv dna.txt")
        sys.exit(1)
    else:
        pass

    csvfile = open(sys.argv[1], "r") 
    csvreader = csv.reader(csvfile)
    header = next(csvreader)
        
    with open(sys.argv[2], "r") as sequencesfile:
        sequence = sequencesfile.read()
    
    for i in range(len(header) - 1):
        sample_data.append(str(longest_match(sequence, header[i + 1])))
    
    for row in csvreader:
        if row[1:] == sample_data:
            print(row[0])
            found = True
            csvfile.close()
            sys.exit(0)
        else:
            pass

    if not found:
        print("No match")
        csvfile.close()
        sys.exit(0)

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):
        count = 0

        while True:

            start = i + count * subsequence_length
            end = start + subsequence_length

            if sequence[start:end] == subsequence:
                count += 1

            else:
                break
        
        longest_run = max(longest_run, count)

    return longest_run

main()
