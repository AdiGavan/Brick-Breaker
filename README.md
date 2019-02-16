"Copyright [2018] Gavan Adrian-George, 334CA"

Nume, prenume: Gavan, Adrian-George

Grupa, seria: 334CA

Tema 1 EGC - Brick breaker

Bonusuri:
=========

1. Aparitie perete jos (bila nu mai poate iesi din joc)
2. Bila "invincibila" (trece direct prin caramida si o distruge direct indiferent de duritatea acesteia)
3. Speedup bila (se mareste viteza bilei)
4. Placa mare (se mareste dimensiunea board-ului)
5. Placa mica (se micsoreaza dimensiunea board-ului) 
6. Bonus viata (adauga o viata in plus)
7. Bonus care ia o viata (scade o viata si daca jucatorul ramane cu 0 vieti pierde jocul)

Culori patrate bonusuri:
========================

1. Aparitie perete jos - Gri
2. Bila "invincibila" - Roz
3. Speedup bila - Alb
4. Placa mare - Albastru deschis
5. Placa mica - Albastru inchis 
6. Bonus viata - Verde deschis
7. Bonus care ia o viata - Verde inchis

Niveluri:
=========

- Jocul are 3 niveluri.
- In fiecare nivel, duritatea caramizilor creste ( nivel 1 - "o viata"; nivel 3- "trei vieti").
- In functie de duritatea curenta a caramizii, culoarea acesteia se schimba.
- La fiecare nivel, se reseteaza numarul vietilor si bonusurile.
- Bonusurile sunt cate 2 din fiecare, distribuie random in caramizi.
- Pentru a castiga trebuie sa treci cele 3 niveluri.

Interactiune:
=============

- Jocul a fost facut sa mearga si daca se mareste fereastra jocului.
- La apasarea click-stanga a mouse-ului, bila se desprinde de pe platforma si incepe sa se miste.
- Platforma se misca stanga-dreapta cu ajutorul mouse-ului.
- Daca jucatorul pierde toate vietile (indiferent de nivel) apare mesajul "L" (invins) si literele "E" 
si "S". Jucatorul poate apasa tasta "E" pentru a iesi din joc. Jucatorul poate asa si tasta "S" pentru 
a incepe din nou jocul, nivelul resetandu-se la nivelul 1.
- Daca jucatorul trece si de ultimul nivel (nivelul 3) apare mesajul "W" (castigator) si, de asemenea, 
lieterel "E" si "S". La fel, jucatorul poate opta pentru inceperea unui nou joc sau pentru inchiderea 
acestuia.
- Jocul are optiunea de "Pauza". Oricand se poate apasa tasta "P" pentru a pune pauza jocului (se pune
pauza inclusiv pe timpul unui bonus, pe scalarea caramizilor sau caderea patratelor bonusurilor). 
Pentru a continua jocul se apasa tasta "O".

Logica implementarii:
=====================

- Se initializeaza mapa (caramizile, bonusurile, peretii, bila, placa, vietile) si se creeaza toate 
mesh-urile ce vor fi folosite pe parcurs. De asemenea, bonusurile sunt atasate random unei caramizi.
- La fiecare update se verifica ce bonusuri sunt activate si li se actualizeaza timpul.
- Se calculeaza ciocnirile cu cei 3 pereti.
- Se trece prin vectorul in care se retin caramizile si se verifica pentru fiecare caramida daca a 
avut loc o coliziune. Coliziunile se verifica astfel: se retine pozitia anterioara a bilei si se 
compara pozitia curenta cu pozitia anterioara si se vede daca a "trecut" peste o muchie a caramizii 
sau nu. Daca a trecut, ne uitam peste ce muchie a trecut si in functie de muchia lovita schimbam 
directia bilei corespunzator.
- Directia X a bilei este data de left_right si Y este data de up_down.
- Se vede daca bila loveste placa si unde anume o loveste. S-a pus o limita asupra unghiului maxim 
de lansare a bilei pentru ca nu cumva bila sa fie lansata paralel cu axa OX.
- Se calculeaza unghiul de lansare. Se vede daca valoarea pentru X va fi negativa sau pozitiva si se 
retine semnul (left_right). 
- Daca bila a iesit din joc, s-au distrus toate caramizile sau vietile au ajuns pe 0 => se repune bila 
pe placa, iar apoi se verifica daca jocul trebuie resetat. Daca jocul trebuie resetat, se verifica daca 
trebuie trecut la nivelul urmator, daca jucatorul a castigat sau daca a pierdut.
- Daca bila trebuie deplasata, se retine pozitia curenta a bilei si apoi se calculeaza noua pozitie a 
bilei astfel: se ia valoarea pentru X in modul si se inmulteste cu semnul directiei acesteia (left_right).
Astfel, daca left_right este negativ => bila se duce in stanga, daca left_right este pozitiv bila se duce 
in dreapta. Similar si pentru up_down.
- Se afiseaza bila, vietile, peretii, placa.
- Se calculeaza bonusurile active si daca sunt patrate pentru bonusuri ce trebuie afisate si se afiseaza.
- Se afiseaza caramizile si se calculeaza valorile de scalare pentru caramizile ce trebuie sa dispara.
