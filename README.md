# V1.1
* V1.1 Programos veikimo principas padarytas pagal V1.0 versiją
* V1.1 Pridėtas programos veikimas naudojant "Klases"
* V1.1 Pridėta laiko analizė naudojant skirtingus kompiliatoriaus optimizavimo flag'us *(laikai lentelėje pateikiami sekundėmis)*

<table>
<thead>
  <tr>
    <th>Flags-&gt;</th>
    <th colspan="2">01</th>
    <th colspan="2">02</th>
    <th colspan="2">03</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td></td>
    <td>STRUCT</td>
    <td>CLASS</td>
    <td>STRUCT</td>
    <td>CLASS</td>
    <td>STRUCT</td>
    <td>CLASS</td>
  </tr>
  <tr>
    <td>100000</td>
    <td>0.063</td>
    <td>0.083</td>
    <td>0.068</td>
    <td>0.057</td>
    <td>0.057</td>
    <td><b>0.04</b></td>
  </tr>
  <tr>
    <td>1000000</td>
    <td>0.492</td>
    <td>0.5</td>
    <td>0.416</td>
    <td>0.437</td>
    <td>0.448</td>
    <td><b>0.386<b></td>
  </tr>
</tbody>
</table>

<i>Išvada:</i> didžiausią skirtumą duoda kompiliatoriaus flag'ai. Naudojant Class su mažesniais duomenų kiekiais, dauguma atvejų programa suveikė greičiau. Su didesniais kiekiais galima padaryti tokią pačią išvadą.

