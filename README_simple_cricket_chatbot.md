# Cricketer Info Chatbot 🏏

A basic console-based chatbot built in Python that provides information about famous cricketers when you type their name.

## 📂 File

| File | Description |
|---|---|
| `simple_cricket_chatbot.py` | Console chatbot that looks up a cricketer by name and returns their info. |

## 🚀 Getting Started

### Prerequisites
- Python 3.8 or higher

### Installation
```bash
git clone https://github.com/<your-username>/<repo-name>.git
cd <repo-name>
```

### Running the Chatbot
```bash
python simple_cricket_chatbot.py
```

## 🧠 How It Works

The program runs a loop that:
1. Asks the user to enter a cricketer's name.
2. Matches the name (exact or partial) against a built-in dictionary of cricketers.
3. Prints the cricketer's country, role, batting style, and key achievements.
4. Shows a list of suggestions if multiple cricketers match, or a "not found" message if none do.
5. Supports a `list` command to show every cricketer it knows.
6. Repeats until the user types `bye`.

## 💡 Example

```
Enter a cricketer's name: kohli

--- Virat Kohli ---
Country      : India
Role         : Batsman (Right-hand)
Batting Style: Right-hand bat
Known For    : Chasing down targets in ODIs, most international centuries among active players
Teams        : India, Royal Challengers Bangalore (IPL)
```

## 🗺️ Roadmap
- [ ] Pull live stats from a cricket API instead of a fixed dictionary
- [ ] Add more players and women's cricket stars
- [ ] Build a simple GUI (Tkinter) or web version (Streamlit)

## 🤝 Contributing

Contributions are welcome! Please see [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines.

## 📄 AI Contribution Log

See [Contribution_Log_cricket_chatbot.md](Contribution_Log_cricket_chatbot.md) for a breakdown of AI-assisted vs. self-contributed work on this project.

## 📄 License

This project is open source and available for academic and educational use.

## 🙋 Author

Built by Kunal as part of an AIML coursework project.
