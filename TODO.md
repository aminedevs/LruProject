### 📝 `TODO.md` — LRU Cache Project

---

#### ✅ **Étape 1 : Implémentation de base (Local LRU)**

* [ ] Implémenter un LRU cache avec :

  * [x] `get(key)`: retourne la valeur ou -1
  * [x] `put(key, value)`: insère ou met à jour une paire
  * [x] Capacité fixe avec éviction LRU
  * [x] Complexité : O(1) pour `get` et `put`

---

#### 🧪 **Étape 2 : Écriture de tests**

* [x] Cas de base (insertion, lecture, eviction)
* [x] Mise à jour d’une clé
* [x] Clé absente
* [ ] Rotation dans la liste LRU
* [ ] Stress test (insertion massive)

---

#### ⚙️ **Étape 3 : Organisation & Clean Code**

* [ ] Séparer le code LRU dans un fichier `LruCache.hpp`
* [ ] Ajouter un fichier `main.cpp` pour les tests
* [ ] Ajouter un `CMakeLists.txt` si besoin
* [ ] Ajouter des assertions ou un mini framework de test

---

#### 🚀 **Option A : Simuler un cache distribué (3 nœuds)**

* [ ] Implémenter un routeur simple :

  * [ ] Fonction `hash(key) -> node`
  * [ ] 3 instances de `LruCache`
* [ ] Le routeur redirige `get/put` vers le bon nœud
* [ ] Ajout de logs pour voir où va chaque clé

---

#### 🧩 **Option B : Réplication**

* [ ] Ajouter un mode de réplication sur 2 nœuds
* [ ] `put(key, value)` écrit sur 2 caches (hash primaire + secondaire)
* [ ] `get(key)` lit sur le cache primaire, fallback sur secondaire

---

#### ⏰ **Option C : Expiration (TTL)**

* [ ] Ajouter un champ `timestamp` par clé
* [ ] `put` accepte une durée de vie optionnelle
* [ ] `get` vérifie l’expiration avant de retourner

---

#### 🧵 **Option D : Accès concurrent**

* [ ] Ajouter des `std::mutex` pour protéger les accès
* [ ] Simuler plusieurs threads qui lisent/écrivent
* [ ] Vérifier cohérence

---

#### 🌐 **Option E : Simuler un système distribué réel**

* [ ] Utiliser des sockets ou REST pour simuler des nœuds
* [ ] Chaque LRU tourne dans un mini serveur
* [ ] Un client appelle `GET`/`PUT` via le réseau

---

#### 📈 **Bonus**

* [ ] Mesurer les performances (temps moyen d’accès)
* [ ] Suivre l’usage mémoire (taille du cache)
* [ ] Ajout d’un mode `verbose`/`silent` pour le debug
