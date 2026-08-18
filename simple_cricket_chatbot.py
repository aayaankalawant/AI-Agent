CRICKETERS = {
    "virat kohli": {
        "full_name": "Virat Kohli",
        "country": "India",
        "role": "Batsman (Right-hand)",
        "batting_style": "Right-hand bat",
        "known_for": "Chasing down targets in ODIs, most international centuries among active players",
        "teams": "India, Royal Challengers Bangalore (IPL)",
    },
    "sachin tendulkar": {
        "full_name": "Sachin Tendulkar",
        "country": "India",
        "role": "Batsman (Right-hand)",
        "batting_style": "Right-hand bat",
        "known_for": "First player to score 100 international centuries, 'God of Cricket'",
        "teams": "India, Mumbai Indians (IPL)",
    },
    "ms dhoni": {
        "full_name": "Mahendra Singh Dhoni",
        "country": "India",
        "role": "Wicketkeeper-Batsman",
        "batting_style": "Right-hand bat",
        "known_for": "Captained India to 2007 T20 World Cup, 2011 World Cup and 2013 Champions Trophy",
        "teams": "India, Chennai Super Kings (IPL)",
    },
    "rohit sharma": {
        "full_name": "Rohit Sharma",
        "country": "India",
        "role": "Batsman (Right-hand)",
        "batting_style": "Right-hand bat",
        "known_for": "Holds record for highest individual score in ODIs (264), 'Hitman'",
        "teams": "India, Mumbai Indians (IPL)",
    },
    "babar azam": {
        "full_name": "Babar Azam",
        "country": "Pakistan",
        "role": "Batsman (Right-hand)",
        "batting_style": "Right-hand bat",
        "known_for": "Fastest to reach several ODI run milestones, former Pakistan captain",
        "teams": "Pakistan, Peshawar Zalmi (PSL)",
    },
    "joe root": {
        "full_name": "Joe Root",
        "country": "England",
        "role": "Batsman (Right-hand)",
        "batting_style": "Right-hand bat",
        "known_for": "One of the leading Test run-scorers of his generation, former England Test captain",
        "teams": "England, Yorkshire",
    },
    "steve smith": {
        "full_name": "Steven Smith",
        "country": "Australia",
        "role": "Batsman (Right-hand)",
        "batting_style": "Right-hand bat",
        "known_for": "Unorthodox technique, one of the highest-rated Test batsmen ever",
        "teams": "Australia, New South Wales",
    },
    "ben stokes": {
        "full_name": "Ben Stokes",
        "country": "England",
        "role": "All-rounder",
        "batting_style": "Left-hand bat",
        "known_for": "Player of the Match in 2019 World Cup final, England Test captain",
        "teams": "England, Durham",
    },
    "kane williamson": {
        "full_name": "Kane Williamson",
        "country": "New Zealand",
        "role": "Batsman (Right-hand)",
        "batting_style": "Right-hand bat",
        "known_for": "Former New Zealand captain, known for calm and technically sound batting",
        "teams": "New Zealand, Northern Districts",
    },
    "jasprit bumrah": {
        "full_name": "Jasprit Bumrah",
        "country": "India",
        "role": "Bowler (Fast)",
        "batting_style": "Right-hand bat",
        "known_for": "Unorthodox bowling action, one of the top fast bowlers across formats",
        "teams": "India, Mumbai Indians (IPL)",
    },
    "shakib al hasan": {
        "full_name": "Shakib Al Hasan",
        "country": "Bangladesh",
        "role": "All-rounder",
        "batting_style": "Left-hand bat",
        "known_for": "Long-time No.1 ranked all-rounder in ODIs",
        "teams": "Bangladesh",
    },
    "pat cummins": {
        "full_name": "Patrick Cummins",
        "country": "Australia",
        "role": "Bowler (Fast)",
        "batting_style": "Right-hand bat",
        "known_for": "Australia's Test and ODI captain, led Australia to 2023 World Cup title",
        "teams": "Australia, New South Wales",
    },
}


def find_cricketer(name):
    """Look up a cricketer by exact or partial (substring) match on name."""
    key = name.strip().lower()

    if key in CRICKETERS:
        return [key]

    matches = [k for k in CRICKETERS if key in k]
    return matches


def print_cricketer_info(key):
    info = CRICKETERS[key]
    print(f"\n--- {info['full_name']} ---")
    print(f"Country      : {info['country']}")
    print(f"Role         : {info['role']}")
    print(f"Batting Style: {info['batting_style']}")
    print(f"Known For    : {info['known_for']}")
    print(f"Teams        : {info['teams']}\n")


def simple_cricket_chatbot():
    print("===== Cricketer Info Chatbot =====")
    print(f"I know about {len(CRICKETERS)} cricketers. Ask me by name!")
    print("Type 'list' to see all names, or 'bye' to exit.\n")

    while True:
        query = input("Enter a cricketer's name: ")

        if query.strip().lower() == "bye":
            print("Goodbye! 🏏")
            break

        if query.strip().lower() == "list":
            print("\nCricketers I know:")
            for k in CRICKETERS:
                print(f" - {CRICKETERS[k]['full_name']}")
            print()
            continue

        if not query.strip():
            print("Please type a name, 'list', or 'bye'.\n")
            continue

        matches = find_cricketer(query)

        if len(matches) == 1:
            print_cricketer_info(matches[0])
        elif len(matches) > 1:
            print("\nMultiple matches found, did you mean one of these?")
            for m in matches:
                print(f" - {CRICKETERS[m]['full_name']}")
            print()
        else:
            print(f"Sorry, I don't have information on '{query}'. Type 'list' to see who I know.\n")


if __name__ == "__main__":
    simple_cricket_chatbot()
