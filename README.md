<b>Světelný přejezd</b>

Projekt simuluje železniční světelný přejezd. LED pásek slouží jako výstup, jako vstup optický senzor HW 201. Řízení zajišťuje Arduino.
V normálním stavu, kdy ani jeden snímač nesnímá překážku, blikají na LED pásku dvě LED bílou barvou. To znamená situaci, kdy přes přejezd nejede vlak.
Ve chvíli, kdy jeden ze snímačů detekuje překážku, rozbliká se na LED pásku 1 LED červeně. K přejezdu se přiblížil vlak z jedné strany.
Je-li překážka nad oběma senzory, nadále bliká červená LED. Vlak je na přejezdu.
Přejde-li překážka nad druhý senzor, světla zhasnou. Vlak přejel přes přejezd, ale stále je v blízkosti přejezdu.
Jakmile se překážka vzdálí od druhého senzoru, nastane běžný stav a začnou opět blikat obě světla. Vlak odjel.

<img width="1518" height="513" alt="image" src="https://github.com/user-attachments/assets/ad5c2a6a-9515-4160-af77-530d308e872f" />




