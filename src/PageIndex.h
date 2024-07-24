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
            display: flex;
            flex-direction: row;
            justify-content: center;
            align-items: center;
            position: relative;
        }

        .logo {
            height: 3rem;
            position: absolute;
            left: 1rem;
        }

        main {
            display: flex;
            flex-direction: column;
            align-items: center;
            padding: 2em;
        }

        .grid-container {
            display: grid;
            grid-template-columns: repeat(3, 1fr);
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

        .card h2 {
            margin-top: 0;
            font-size: 1.5rem;
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

        <svg class="logo" viewBox="0 0 1000 1000">
            <path fill="white"
                d="M143.74,240.62l108.36-62.6v504.11l-88.65,88.65-19.72-11.39c-28.79-16.6-46.51-47.3-46.51-80.55v-357.65c0-33.25,17.72-63.95,46.51-80.55Z" />
            <path fill="white"
                d="M753.15,181.09l-408.02,408.02V124.35l108.36-62.6c28.79-16.6,64.23-16.6,93.02,0l206.64,119.34Z" />
            <path fill="white"
                d="M902.76,321.17v357.65c0,33.25-17.72,63.95-46.51,80.55l-19.72,11.39-270.77-270.77,270.77-270.77,19.72,11.39c28.79,16.6,46.51,47.3,46.51,80.55Z" />
            <path fill="#FBD008"
                d="M753.15,818.91l-206.64,119.34c-28.79,16.6-64.23,16.6-93.02,0l-206.64-119.34,253.15-253.15,253.15,253.15Z" />

        </svg>
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
            <!--BME Humidity-->
            <div class="card">
                <h2>Humidity 1: </h2>
                <p>
                    <span id="BMEHumidityValue">0</span>
                    <sup class="units">%</sup>
                </p>
            </div>
            <!--BME Pressure-->
            <div class="card">
                <h2>Pressure 1: </h2>
                <p>
                    <span id="BMEPressureValue">0</span>
                    <sup class="units">mb</sup>
                </p>
            </div>
            <!--BMP Temperature-->
            <div class="card">
                <h2>Temperature 2: </h2>
                <p>
                    <span id="BMPTemperatureValue">0</span>
                    <sup class="units">&deg;C</sup>
                </p>
            </div>
            <!--DHT Humidity-->
            <div class="card">
                <h2>Humidity 2: </h2>
                <p>
                    <span id="DHTHumidityValue">0</span>
                    <sup class="units">%</sup>
                </p>
            </div>
            <!--BMP Pressure-->
            <div class="card">
                <h2>Pressure 2: </h2>
                <p>
                    <span id="BMPPressureValue">0</span>
                    <sup class="units">mb</sup>
                </p>
            </div>
            <!--AS5600 Wind Direction-->
            <div class="card">
                <h2>Wind Direction: </h2>
                <p>
                    <span id="WindDirectionValue">0</span>
                    <sup class="units">&deg;</sup>
                </p>
            </div>
            <!--BH1750 Light-->
            <div class="card">
                <h2>Light Intensity: </h2>
                <p>
                    <span id="LightValue">0</span>
                    <sup class="units">lux</sup>
                </p>
            </div>
            <!--Precipitation-->
            <div class="card">
                <h2>Precipitation: </h2>
                <p>
                    <span id="PrecipitationValue">0</span>
                    <sup class="units">mm</sup>
                </p>
            </div>
            <!--Wind Speed-->
            <div class="card">
                <h2>Wind Speed: </h2>
                <p>
                    <span id="WindSpeedValue">0</span>
                    <sup class="units">kph</sup>
                </p>
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

        // BME Temperature
        function getBMETemperatureData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("BMETemperatureValue").innerHTML =
                        this.responseText;
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
                    document.getElementById("BMEHumidityValue").innerHTML =
                        this.responseText;
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
                    document.getElementById("BMEPressureValue").innerHTML =
                        this.responseText;
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
                    document.getElementById("BMPTemperatureValue").innerHTML =
                        this.responseText;
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
                    document.getElementById("DHTHumidityValue").innerHTML =
                        this.responseText;
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
                    document.getElementById("BMPPressureValue").innerHTML =
                        this.responseText;
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
                    document.getElementById("WindDirectionValue").innerHTML =
                        this.responseText;
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
                    document.getElementById("LightValue").innerHTML =
                        this.responseText;
                }
            };
            xhttp.open("GET", "readLight", true);
            xhttp.send();
        }

        // Precipitation
        function getPrecipitationData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("PrecipitationValue").innerHTML =
                        this.responseText;
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
                    document.getElementById("WindSpeedValue").innerHTML =
                        this.responseText;
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
            getPrecipitationData();
            getWindSpeedData();
        }
    </script>
</body>

</html>
)=====";