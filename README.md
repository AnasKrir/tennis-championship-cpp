# 🎾 Tennis Championship — Application console C++

![C++](https://img.shields.io/badge/C++-17-blue.svg)
![Status](https://img.shields.io/badge/Status-Stable-success)
![Platform](https://img.shields.io/badge/Platform-macOS%20%7C%20Windows%20%7C%20Linux-lightgrey)
![License](https://img.shields.io/badge/License-MIT-blue.svg)

Application **console C++** permettant de gérer un **tournoi de tennis** :  
inscription des joueurs, création des matchs (au hasard), suivi des scores et génération des classements.

---

## 📌 Sommaire

1. [Fonctionnalités](#-fonctionnalités)
2. [Stack technique](#-stack-technique)
3. [Architecture](#-architecture)
4. [Démarrage rapide](#-démarrage-rapide)
5. [Auteurs](#-auteurs)
6. [Licence](#-licence)

---

## ✅ Fonctionnalités

🎾 **Gestion des joueurs** (ajout, suppression, affichage)  
📅 **Organisation des matchs** avec tirage automatique  
🏆 **Calcul du classement final** selon les victoires  
📜 **Affichage clair des résultats** dans la console  

---

## 🛠️ Stack technique

| Technologie | Description |
|--------------|--------------|
| **Langage** | C++ 17 |
| **IDE recommandé** | VS Code / CLion / Code::Blocks / Xcode /Dev-C++|
| **Système** | macOS, Windows, Linux |
| **Compilation** | g++ ou clang++ |
| **Fichiers inclus** | `TENNIS.cpp`|

---

## 🏗️ Architecture

```
tennis-championship-cpp/
├── TENNIS.cpp # Code source principal
├── README.md # Ce fichier
└── .gitignore # Fichiers à ignorer par Git
```

**Organisation du code :**
- **Structures principales** : Joueur, Match, Tournoi  
- **Fonctions clés** : gestion des matchs au hasard, affichage des résultats, réinitialisation du tournoi  

---

## 🚀 Démarrage rapide

### 1️⃣ Prérequis

✅ Avoir installé **g++ (ou clang++)**  
✅ Avoir **Git** et un terminal (macOS/Linux) ou **PowerShell** (Windows)

### 2️⃣ Compilation

```
# Compilation (macOS / Linux)

g++ -std=c++17 TENNIS.cpp -o tennis
```
ou sous Windows :

```
g++ -std=c++17 TENNIS.cpp -o tennis.exe
```

### 3️⃣ Exécution

```
./tennis
```

ou

```
tennis.exe
```
---

## 👥 Auteurs

Anas KRIR — Développeur principal

---

## 📄 Licence

Projet sous licence MIT.<br/>
✅ Libre d’utiliser, modifier et distribuer le code.

© 2023 — Anas KRIR

---


