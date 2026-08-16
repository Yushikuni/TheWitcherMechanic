# 🧿 The Witcher Mechanic

A distance-based detection mechanic for Unreal Engine 5, inspired by the medallion system from *The Witcher* series. The medallion senses nearby enemies or magic within a radius, with signal strength scaling by proximity — the closer the threat, the stronger the signal.

> Built to be a clean, reusable detection system — not tied to any specific game project. Fork it, extend it, or drop it into your own prototype.

---

## 🎮 Features

- 🔍 Enemy & magic detection within a defined radius
- 🧿 Medallion toggles between enemy/magic sensing
- 🛠️ Blueprint–C++ hybrid logic using `AMedailon` and `ATheWitcher` classes
- 🎯 Visual debug feedback (spheres)
- 🔊 Extendable for sound, particles, UI integration

---

## 🛠 Requirements

- [Unreal Engine 5](https://www.unrealengine.com/en-US/download) installed
- Windows or macOS system with UE5 support
- Basic understanding of Blueprints and/or C++

---

## 🚀 Installation

1. Clone the repo:

```bash
git clone https://github.com/Yushikuni/TheWitcherMechanic.git
```

2. Open the .uproject file in Unreal Engine 5
3. Press Play to test the mechanic in the level

---



## ⌨️ Controls & Usage

| Key      | Action                                           |
| -------- | ------------------------------------------------ |
| `Y`    | Trigger medallion detection pulse                |
| `Tab`  | Toggle detection mode (enemy ↔ magic)           |
| `Play` | Start the detection system in the editor preview |

To integrate the system into your own project, reference:

- `AMedailon` — detection logic, signal strength calculation, mode toggle
- `ATheWitcher` — player actor that owns and activates the medallion

---

## 📸 Screenshots & Demo

<a href="https://youtu.be/lN4yqSardvc?si=5PvGqolBlZs6KkZK">
  <img src="https://github.com/user-attachments/assets/8e5ac202-be9c-4b25-9465-b4607f3e5c83" alt="Medallion Effect" width="300" height="300">
</a><br> Click to watch the demo on YouTube.
*The Witcher Medallion in action, detecting an enemy.*<br>
OR here: <a href="https://youtu.be/lN4yqSardvc?si=5PvGqolBlZs6KkZK"/>

[https://youtu.be/lN4yqSardvc?si=5PvGqolBlZs6KkZK](https://youtu.be/lN4yqSardvc?si=5PvGqolBlZs6KkZK)

## 🔮 TODO

- [X] Distance-based detection signal (medallion strength scales with proximity)
- [X] Enemy/Magic detection mode toggle
- [ ] Sound FX & particle feedback (currently debug text only)
- [X] Cooldown system for medallion pulses
- [X] Package as a proper UE5 Plugin with public A

<!-- AUTHOR: START -->

## 🙋‍♀️ Author
Created by Yushikuni
Feel free to fork, star ⭐, and use this mechanic in your own gameplay prototypes!

📬 Contact: huskvenimrah@gmail.com
<!-- AUTHOR:END-->

## [💡 Acknowledgements](https://youtu.be/lN4yqSardvc?si=5PvGqolBlZs6KkZK)

[The Unreal Engine dev community ❤️
Gameplay inspiration from The Witcher 1 &amp; 3
Assets used under fair-use/educational license ](https://youtu.be/lN4yqSardvc?si=5PvGqolBlZs6KkZK)
