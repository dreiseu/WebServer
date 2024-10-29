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
            <!--BME 1 Temperature-->
            <div class="card">
                <h2>Temperature 1: </h2>
                <p>
                    <span id="BMETemperatureValue">0</span>
                    <sup class="units">&deg;C</sup>
                </p>
            </div>
            <!--BME 1 Humidity-->
            <div class="card">
                <h2>Humidity 1: </h2>
                <p>
                    <span id="BMEHumidityValue">0</span>
                    <sup class="units">%</sup>
                </p>
            </div>
            <!--BME 1 Pressure-->
            <div class="card">
                <h2>Pressure 1: </h2>
                <p>
                    <span id="BMEPressureValue">0</span>
                    <sup class="units">mb</sup>
                </p>
            </div>
            <!--BME 2 Temperature-->
            <div class="card">
                <h2>Temperature 2: </h2>
                <p>
                    <span id="BMPTemperatureValue">0</span>
                    <sup class="units">&deg;C</sup>
                </p>
            </div>
            <!--BME 2 Humidity-->
            <div class="card">
                <h2>Humidity 2: </h2>
                <p>
                    <span id="DHTHumidityValue">0</span>
                    <sup class="units">%</sup>
                </p>
            </div>
            <!--BME 2 Pressure-->
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
            getBME1tempData();
            getBME2tempData();
            getBME3tempData();
            getBME1humidData();
            getBME2humidData();
            getBME3humidData();
            getBME1presData();
            getBME2presData();
            getBME3presData();
            getWindDirectionData();
            getLightData();
            getUVData();
            getPrecipitationData();
            getWindSpeedData();
            getGustData();
        }, 60000);

        setInterval(function () {
            // Call a function repetatively with 1 Second interval
            Time_Date();
        }, 1000);

        // BME 1 Temperature
        function getBME1tempData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("BME1tempValue").innerHTML =
                        this.responseText;
                }
            };
            xhttp.open("GET", "readBME1temp", true);
            xhttp.send();
        }
        // BME 2 Temperature
        function getBME2tempData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("BME2tempValue").innerHTML =
                        this.responseText;
                }
            };
            xhttp.open("GET", "readBME2temp", true);
            xhttp.send();
        }

        // BME 3 Temperature
        function getBME3tempData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("BME3tempValue").innerHTML =
                        this.responseText;
                }
            };
            xhttp.open("GET", "readBME3temp", true);
            xhttp.send();
        }

        // BME 1 Humidity
        function getBME1humidData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("BME1humidValue").innerHTML =
                        this.responseText;
                }
            };
            xhttp.open("GET", "readBME1humid", true);
            xhttp.send();
        }
        // BME 2 Humidity
        function getBME2humidData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("BME2humidValue").innerHTML =
                        this.responseText;
                }
            };
            xhttp.open("GET", "readBME2humid", true);
            xhttp.send();
        }

        // BME 3 Humidity
        function getBME3humidData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("BME3humidValue").innerHTML =
                        this.responseText;
                }
            };
            xhttp.open("GET", "readBME3humid", true);
            xhttp.send();
        }

        // BME 1 Pressure
        function getBME1presData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("BME1presValue").innerHTML =
                        this.responseText;
                }
            };
            xhttp.open("GET", "readBME1pres", true);
            xhttp.send();
        }
        // BME 2 Pressure
        function getBME2presData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("BME2presValue").innerHTML =
                        this.responseText;
                }
            };
            xhttp.open("GET", "readBME2pres", true);
            xhttp.send();
        }

        // BME 3 Pressure
        function getBME3presData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("BME3presValue").innerHTML =
                        this.responseText;
                }
            };
            xhttp.open("GET", "readBME3pres", true);
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

        // WindSpeed
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

        // Gust
        function getGustData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("GustValue").innerHTML =
                        this.responseText;
                }
            };
            xhttp.open("GET", "readGust", true);
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
            getBME1tempData();
            getBME2tempData();
            getBME3tempData();
            getBME1presData();
            getBME2presData();
            getBME3presData();
            getBME1humidData();
            getBME2humidData();
            getBME3humidData();
            getWindDirectionData();
            getLightData();
            getPrecipitationData();
            getWindSpeedData();
            getGustData();
        }
    </script>
</body>

</html>
)=====";