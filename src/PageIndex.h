const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<head>
    <title>Kloudtech Weather Data</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta http-equiv="refresh">
    <meta charset="utf-8">
    <link rel="icon" type="image/png" href="icon.png">
    <style>
        :root {
            margin: 0;
            padding: 0;
        }

        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
        }

        header {
            background-color: #333;
            color: #fff;
            padding: 1em;
            text-align: center;
        }

        main {
            display: flex;
            flex-direction: column;
            align-items: center;
            padding: 2em;
        }

        .grid-container {
            display: grid;
            grid-template-columns: repeat(4, 1fr);
            gap: 10px;
        }

        .card {
            background-color: #fff;
            padding: 1em;
            border: 1px solid #ddd;
            border-radius: 10px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
            display: flex;
            flex-direction: column;
            align-items: center;
        }

        .card-historical {
            background-color: #fff;
            padding: 1em;
            border: 1px solid #ddd;
            border-radius: 10px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
            display: flex;
            flex-direction: column;
            grid-column: 2/ span 3;
        }

        .card h2 {
            margin: 0;
            padding: 0;
            font-size: 1.5rem;
        }

        .card-historical h2 {
            margin: 0;
            padding: 0;
        }

        .card-historical div {
            padding-top: 0.5rem;
            font-size: medium;
            display: flex;
            flex-direction: row;
            justify-content: space-evenly;
            align-items: center;
            flex-grow: 1;
        }
        .card-historical div div {
            padding: 0 0.5rem 0 0.5rem;
        }

        .button-section {
            margin-top: 2em;
            text-align: center;
        }

        .button {
            background-color: #333;
            color: #fff;
            border: none;
            padding: 10px 20px;
            font-size: 16px;
            cursor: pointer;
            border-radius: 10px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1)
        }

        .button:hover {
            background-color: #444;
        }

        .time-date-section {
            margin-top: 2em;
            text-align: center;
        }

        .units {
            font-size: 0.8em;
        }
    </style>
</head>

<body>
    <header>
        <h1>Kloudtech Weather Data</h1>
    </header>
    <main>
        <section class="grid-container">
            <!--BME Temperature-->
            <div class="card">
                <h2>Temperature 1: </h2>
                <p>
                    <span id="BMETemperatureValue">0</span>
                    <sup class="units">&deg;C</sup>
                </p>
            </div>
            <div class="card-historical">
                <h2 class="history-head">Temperature 1 History</h2>
                <div id="temperature1History"></div>
            </div>
            <!--BME Humidity-->
            <div class="card">
                <h2>Humidity 1: </h2>
                <p>
                    <span id="BMEHumidityValue">0</span>
                    <sup class="units">%</sup>
                </p>
            </div>
            <div class="card-historical">
                <h2 class="history-head">Humidity 1 History</h2>
                <div id="humidity1History"></div>
            </div>
            <!--BME Pressure-->
            <div class="card">
                <h2>Pressure 1: </h2>
                <p>
                    <span id="BMEPressureValue">0</span>
                    <sup class="units">mb</sup>
                </p>
            </div>
            <div class="card-historical">
                <h2 class="history-head">Pressure 1 History</h2>
                <div id="pressure1History"></div>
            </div>
            <!--BMP Temperature-->
            <div class="card">
                <h2>Temperature 2: </h2>
                <p>
                    <span id="BMPTemperatureValue">0</span>
                    <sup class="units">&deg;C</sup>
                </p>
            </div>
            <div class="card-historical">
                <h2 class="history-head">Temperature 2 History</h2>
                <div id="temperature2History"></div>
            </div>
            <!--DHT Humidity-->
            <div class="card">
                <h2>Humidity 2: </h2>
                <p>
                    <span id="DHTHumidityValue">0</span>
                    <sup class="units">%</sup>
                </p>
            </div>

            <div class="card-historical">
                <h2 class="history-head">Humidity 2 History</h2>
                <div id="humidity2History"></div>
            </div>
            <!--BMP Pressure-->
            <div class="card">
                <h2>Pressure 2: </h2>
                <p>
                    <span id="BMPPressureValue">0</span>
                    <sup class="units">mb</sup>
                </p>
            </div>

            <div class="card-historical">
                <h2 class="history-head">Pressure 2 History</h2>
                <div id="pressure2History"></div>
            </div>
            <!--AS5600 Wind Direction-->
            <div class="card">
                <h2>Wind Direction: </h2>
                <p>
                    <span id="WindDirectionValue">0</span>
                    <sup class="units">&deg;</sup>
                </p>
            </div>
            <div class="card-historical">
                <h2 class="history-head">Wind Direction History</h2>
                <div id="windDirectionHistory"></div>
            </div>
            <!--BH1750 Light-->
            <div class="card">
                <h2>Light Intensity: </h2>
                <p>
                    <span id="LightValue">0</span>
                    <sup class="units">lux</sup>
                </p>
            </div>
            <div class="card-historical">
                <h2 class="history-head">Light Intensity History</h2>
                <div id="lightHistory"></div>
            </div>
            <!--UV-->
            <div class="card">
                <h2>UV Intensity: </h2>
                <p>
                    <span id="UVValue">0</span>
                    <sup class="units">mW/cm2</sup>
                </p>
            </div>
            <div class="card-historical">
                <h2 class="history-head">UV Intensity History</h2>
                <div id="uvHistory"></div>
            </div>
            <!--Precipitation-->
            <div class="card">
                <h2>Precipitation: </h2>
                <p>
                    <span id="PrecipitationValue">0</span>
                    <sup class="units">mm</sup>
                </p>
            </div>
            <div class="card-historical">
                <h2 class="history-head">Precipitation History</h2>
                <div id="rainHistory"></div>
            </div>
            <!--Wind Speed-->
            <div class="card">
                <h2>Wind Speed: </h2>
                <p>
                    <span id="WindSpeedValue">0</span>
                    <sup class="units">kph</sup>
                </p>
            </div>
            <div class="card-historical">
                <h2 class="history-head">Wind Speed History</h2>
                <div id="windSpeedHistory"></div>
            </div>
        </section>
        <section class="button-section">
            <!-- <button class="button" onclick="downloadCSV()">Download CSV</button> -->
            <button class="button" onclick="refreshData()">Refresh Data</button>
        </section>
        <section class="time-date-section">
            <i class="far fa-clock" style="font-size:1.0rem;color:#f7dc68;"></i>
            <span style="font-size:1.0rem;">Time: </span>
            <span id="time" style="font-size:1.0rem;"></span>

            <i class="far fa-calendar-alt" style="font-size:1.0rem;color:#f7dc68" ;></i>
            <span style="font-size:1.0rem;">Date: </span>
            <span id="date" style="font-size:1.0rem;"></span>
        </section>
    </main>
    <script>
        setInterval(function () {
            getBMETemperatureData();
            getBMEHumidityData();
            getBMEPressureData();
            getBMPTemperatureData();
            getBMPPressureData();
            getDHTHumidityData();
            getWindDirectionData();
            getLightData();
            getUVData();
            getPrecipitationData();
            getWindSpeedData();
        }, 60000);

        setInterval(function () {
            // Call a function repetatively with 1 Second interval
            Time_Date();
        }, 1000);

        let temperature1Array = ["0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00"];
        let humidity1Array = ["0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00"];
        let pressure1Array = ["0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00"];
        let temperature2Array = ["0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00"];
        let humidity2Array = ["0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00"];
        let pressure2Array = ["0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00"];
        let windDirectionArray = ["0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00"];
        let lightArray = ["0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00"];
        let uvArray = ["0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00"];
        let rainArray = ["0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00"];
        let windSpeedArray = ["0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00", "0.00"];



        // BME Temperature
        function getBMETemperatureData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    let newValue = this.responseText;
                    console.log(newValue);
                    console.log(temperature1Array);

                    temperature1Array.unshift(newValue); // insert new value at index 0
                    temperature1Array.pop(); // remove last item

                    let list = document.getElementById('temperature1History');
                    while (list.firstChild) {
                        list.removeChild(list.firstChild);
                    }

                    temperature1Array.forEach(item => {
                        let listItem = document.createElement('div');
                        listItem.textContent = item;
                        list.appendChild(listItem);
                    });

                    console.log(temperature1Array);
                    document.getElementById("BMETemperatureValue").innerHTML = newValue;
                }
            };
            xhttp.open("GET", "readBMETemperature", true);
            xhttp.send();
        }

        // BME Humidity
        function getBMEHumidityData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    let newValue = this.responseText;
                    console.log(newValue);
                    console.log(humidity1Array);

                    humidity1Array.unshift(newValue); // insert new value at index 0
                    humidity1Array.pop(); // remove last item

                    let list = document.getElementById('humidity1History');
                    while (list.firstChild) {
                        list.removeChild(list.firstChild);
                    }

                    humidity1Array.forEach(item => {
                        let listItem = document.createElement('div');
                        listItem.textContent = item;
                        list.appendChild(listItem);
                    });

                    console.log(humidity1Array);
                    document.getElementById("BMEHumidityValue").innerHTML = newValue;
                }
            };
            xhttp.open("GET", "readBMEHumidity", true);
            xhttp.send();
        }

        // BME Pressure
        function getBMEPressureData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    let newValue = this.responseText;

                    pressure1Array.unshift(newValue); // insert new value at index 0
                    pressure1Array.pop(); // remove last item

                    let list = document.getElementById('pressure1History');
                    while (list.firstChild) {
                        list.removeChild(list.firstChild);
                    }

                    pressure1Array.forEach(item => {
                        let listItem = document.createElement('div');
                        listItem.textContent = item;
                        list.appendChild(listItem);
                    });

                    document.getElementById("BMEPressureValue").innerHTML = newValue;
                }
            };
            xhttp.open("GET", "readBMEPressure", true);
            xhttp.send();
        }

        // BMP Temperature
        function getBMPTemperatureData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    let newValue = this.responseText;

                    temperature2Array.unshift(newValue); // insert new value at index 0
                    temperature2Array.pop(); // remove last item

                    let list = document.getElementById('temperature2History');
                    while (list.firstChild) {
                        list.removeChild(list.firstChild);
                    }

                    temperature2Array.forEach(item => {
                        let listItem = document.createElement('div');
                        listItem.textContent = item;
                        list.appendChild(listItem);
                    });
                    document.getElementById("BMPTemperatureValue").innerHTML = newValue;
                }
            };
            xhttp.open("GET", "readBMPTemperature", true);
            xhttp.send();
        }

        // DHT Humidity
        function getDHTHumidityData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    let newValue = this.responseText;

                    humidity2Array.unshift(newValue); // insert new value at index 0
                    humidity2Array.pop(); // remove last item

                    let list = document.getElementById('humidity2History');
                    while (list.firstChild) {
                        list.removeChild(list.firstChild);
                    }

                    humidity2Array.forEach(item => {
                        let listItem = document.createElement('div');
                        listItem.textContent = item;
                        list.appendChild(listItem);
                    });

                    document.getElementById("DHTHumidityValue").innerHTML = newValue;
                }
            };
            xhttp.open("GET", "readDHTHumidity", true);
            xhttp.send();
        }

        // BMP Pressure
        function getBMPPressureData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    let newValue = this.responseText;

                    pressure2Array.unshift(newValue); // insert new value at index 0
                    pressure2Array.pop(); // remove last item

                    let list = document.getElementById('pressure2History');
                    while (list.firstChild) {
                        list.removeChild(list.firstChild);
                    }

                    pressure2Array.forEach(item => {
                        let listItem = document.createElement('div');
                        listItem.textContent = item;
                        list.appendChild(listItem);
                    });
                    document.getElementById("BMPPressureValue").innerHTML = newValue;
                }
            };
            xhttp.open("GET", "readBMPPressure", true);
            xhttp.send();
        }

        // Wind Direction
        function getWindDirectionData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    let newValue = this.responseText;

                    windDirectionArray.unshift(newValue); // insert new value at index 0
                    windDirectionArray.pop(); // remove last item

                    let list = document.getElementById('windDirectionHistory');
                    while (list.firstChild) {
                        list.removeChild(list.firstChild);
                    }

                    windDirectionArray.forEach(item => {
                        let listItem = document.createElement('div');
                        listItem.textContent = item;
                        list.appendChild(listItem);
                    });

                    document.getElementById("WindDirectionValue").innerHTML = newValue;
                }
            };
            xhttp.open("GET", "readWindDirection", true);
            xhttp.send();
        }

        // Light
        function getLightData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    let newValue = this.responseText;

                    lightArray.unshift(newValue); // insert new value at index 0
                    lightArray.pop(); // remove last item

                    let list = document.getElementById('lightHistory');
                    while (list.firstChild) {
                        list.removeChild(list.firstChild);
                    }

                    lightArray.forEach(item => {
                        let listItem = document.createElement('div');
                        listItem.textContent = item;
                        list.appendChild(listItem);
                    });

                    document.getElementById("LightValue").innerHTML = newValue;
                }
            };
            xhttp.open("GET", "readLight", true);
            xhttp.send();
        }

        // UV
        function getUVData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    let newValue = this.responseText;

                    uvArray.unshift(newValue); // insert new value at index 0
                    uvArray.pop(); // remove last item

                    let list = document.getElementById('uvHistory');
                    while (list.firstChild) {
                        list.removeChild(list.firstChild);
                    }

                    uvArray.forEach(item => {
                        let listItem = document.createElement('div');
                        listItem.textContent = item;
                        list.appendChild(listItem);
                    });
                    document.getElementById("UVValue").innerHTML = newValue;
                }
            };
            xhttp.open("GET", "readUV", true);
            xhttp.send();
        }

        // Precipitation
        function getPrecipitationData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    let newValue = this.responseText;

                    rainArray.unshift(newValue); // insert new value at index 0
                    rainArray.pop(); // remove last item

                    let list = document.getElementById('rainHistory');
                    while (list.firstChild) {
                        list.removeChild(list.firstChild);
                    }

                    rainArray.forEach(item => {
                        let listItem = document.createElement('div');
                        listItem.textContent = item;
                        list.appendChild(listItem);
                    });
                    document.getElementById("PrecipitationValue").innerHTML = newValue;
                }
            };
            xhttp.open("GET", "readPrecipitation", true);
            xhttp.send();
        }

        // Wind Speed
        function getWindSpeedData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {

                    let newValue = this.responseText;

                    windSpeedArray.unshift(newValue); // insert new value at index 0
                    windSpeedArray.pop(); // remove last item

                    let list = document.getElementById('windSpeedHistory');
                    while (list.firstChild) {
                        list.removeChild(list.firstChild);
                    }

                    windSpeedArray.forEach(item => {
                        let listItem = document.createElement('div');
                        listItem.textContent = item;
                        list.appendChild(listItem);
                    });
                    document.getElementById("WindSpeedValue").innerHTML = newValue;
                }
            };
            xhttp.open("GET", "readWindSpeed", true);
            xhttp.send();
        }

        // Time and Date
        function Time_Date() {
            var t = new Date();
            document.getElementById("time").innerHTML = t.toLocaleTimeString();
            var d = new Date();
            const dayNames = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
            const monthNames = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];
            document.getElementById("date").innerHTML = dayNames[d.getDay()] + ", " + d.getDate() + "-" + monthNames[d.getMonth()] + "-" + d.getFullYear();
        }

        // // Download CSV file
        // function downloadCSV() {
        //     var xhttp = new XMLHttpRequest();
        //     xhttp.onreadystatechange = function () {
        //         if (this.readyState == 4 && this.status == 200) {
        //             var blob = new Blob([this.responseText], { type: 'text/csv' });
        //             var url = window.URL.createObjectURL(blob);
        //             var a = document.createElement('a');
        //             a.href = url;
        //             a.download = 'data.csv';
        //             document.body.appendChild(a);
        //             a.click();
        //             document.body.removeChild(a);
        //         }
        //     };
        //     xhttp.open("GET", "downloadCSV", true);
        //     xhttp.send();
        // }

        // Refresh Data
        function refreshData() {
            getBMETemperatureData();
            getBMEHumidityData();
            getBMEPressureData();
            getBMPTemperatureData();
            getBMPPressureData();
            getDHTHumidityData();
            getWindDirectionData();
            getLightData();
            getUVData();
            getPrecipitationData();
            getWindSpeedData();
        }



    </script>
</body>

</html>
)=====";