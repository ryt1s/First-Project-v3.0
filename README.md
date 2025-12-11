# FirstProject v3.0

## Aprašymas
Tai yra **v3.0** versija, paremta ankstesne v1.5, papildyta **Windows diegimo paketu** (`FirstProjectSetup.exe`). Programa leidžia tvarkyti studentų duomenis, juos skaityti iš failų, rūšiuoti ir skirstyti į grupes (vargsiukai/kietiakai).

### Naujos savybės v3.0
- Pilnas diegimo paketas: `FirstProjectSetup.exe`
- Programa instaliuojama į: `C:\Program Files\VU\Vardenis-Pavardenis`
- Sukuriami **Start meniu** ir **Darbalaukio** šortkatai
---

## Diegimas
1. Paleiskite `FirstProjectSetup.exe`
2. Sekite instrukcijas
3. Po instaliacijos programa pasiekiama per **Start meniu** arba **Darbalaukio** šortkatą
4. Pašalinti galima per „Programos ir funkcijos“ (Add/Remove Programs) arba paleidžiant `unins000.exe`

---

## Diegimo failai
- `FirstProjectSetup.exe` pateikiamas repozitorijoje **releases** kataloge
- Šio failo dėka programa tvarkingai įdiegiama į Windows sistemą su visais reikiamais aplankais ir šortkatais
---

## Pastaba
- DLL failas šioje versijoje nėra naudojamas.
- Įrašius vartotojo failą (pvz. `studentai_1000.txt`), programos generuojami `vargsiukai.txt` ir `kietiakai.txt` failai dar gali būti rankiniu būdu įdėti į katalogą, jei įdiegimo metu nenusikopijuojami automatiškai.
