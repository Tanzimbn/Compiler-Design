### **Context-Free Grammar (CFG)**  
A **Context-Free Grammar (CFG)** is a formal grammar used to define the syntax of a language. It consists of a set of rules (productions) that describe how symbols in the language can be formed.  

### **Components of CFG**  
A CFG consists of:  
- **Non-Terminals (V):** Variables that can be replaced (e.g., `S`, `A`, `B`).  
- **Terminals (Σ):** Fixed symbols (e.g., `a`, `b`, `c`).  
- **Production Rules (P):** Rules defining how non-terminals expand.  
- **Start Symbol (S):** The symbol from which derivations begin.  

### **Example CFG (Alphabet-based)**  
Consider a simple language of strings containing `a` and `b`, where every `a` is followed by at least one `b`:  

```
S → aB  
B → bB | b  
```

#### **Derivation Example:**  
Using the rules above, we can generate valid strings:  
- `S → aB → ab`  
- `S → aB → abB → abb`  
- `S → aB → abB → abbB → abbb`  

Invalid strings like `a` or `aba` are **not** allowed in this grammar.  

### **Usage in Parsing**  
CFGs are widely used in **compilers**, **natural language processing**, and **formal language theory** to define structured languages like programming languages and human languages.  

### sample input
```C++
3
S BAB
A aA a e
B bB b
3
bb
b
baab
```

### sample output
```C++
Accepted
Rejected
Accepted
```