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
                    <span id="BMETemperatureValue">%T1%</span>
                    <sup class="units">&deg;C</sup>
                </p>
            </div>
            <!--BME Humidity-->
            <div class="card">
                <h2>Humidity 1: </h2>
                <p>
                    <span id="BMEHumidityValue">%H1%</span>
                    <sup class="units">&#37</sup>
                </p>
            </div>
            <!--BME Pressure-->
            <div class="card">
                <h2>Pressure 1: </h2>
                <p>
                    <span id="BMEPressureValue">%P1%</span>
                    <sup class="units">mb</sup>
                </p>
            </div>
            <!--BMP Temperature-->
            <div class="card">
                <h2>Temperature 2: </h2>
                <p>
                    <span id="BMPTemperatureValue">%T2%</span>
                    <sup class="units">&deg;C</sup>
                </p>
            </div>
            <!--DHT Humidity-->
            <div class="card">
                <h2>Humidity 2: </h2>
                <p>
                    <span id="DHTHumidityValue">%H2%</span>
                    <sup class="units">&#37</sup>
                </p>
            </div>
            <!--BMP Pressure-->
            <div class="card">
                <h2>Pressure 2: </h2>
                <p>
                    <span id="BMPPressureValue">%P2%</span>
                    <sup class="units">mb</sup>
                </p>
            </div>
            <!--AS5600 Wind Direction-->
            <div class="card">
                <h2>Wind Direction: </h2>
                <p>
                    <span id="WindDirectionValue">%WINDDIR%</span>
                    <sup class="units">&deg;</sup>
                </p>
            </div>
            <!--BH1750 Light-->
            <div class="card">
                <h2>Light Intensity: </h2>
                <p>
                    <span id="LightValue">%LIGHT%</span>
                    <sup class="units">lux</sup>
                </p>
            </div>
            <!--Precipitation-->
            <div class="card">
                <h2>Precipitation: </h2>
                <p>
                    <span id="PrecipitationValue">%RAIN%</span>
                    <sup class="units">mm</sup>
                </p>
            </div>
            <!--Wind Speed-->
            <div class="card">
                <h2>Wind Speed: </h2>
                <p>
                    <span id="WindSpeedValue">%WINDSPEED%</span>
                    <sup class="units">kph</sup>
                </p>
            </div>
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
        if (!!window.EventSource) {
            var source = new EventSource('/events');

            source.addEventListener('open', function (e) {
                console.log("Events Connected");
            }, false);
            source.addEventListener('error', function (e) {
                if (e.target.readyState != EventSource.OPEN) {
                    console.log("Events Disconnected");
                }
            }, false);

            source.addEventListener('message', function (e) {
                console.log("message", e.data);
            }, false);



            source.addEventListener('t1', function (e) {
                console.log("t1", e.data);
                document.getElementById("BMETemperatureValue").innerHTML = e.data;
            }, false);
            source.addEventListener('h1', function (e) {
                console.log("h1", e.data);
                document.getElementById("BMEHumidityValue").innerHTML = e.data;
            }, false);
            source.addEventListener('p1', function (e) {
                console.log("p1", e.data);
                document.getElementById("BMEPressureValue").innerHTML = e.data;
            }, false);
            source.addEventListener('t2', function (e) {
                console.log("t2", e.data);
                document.getElementById("BMPTemperatureValue").innerHTML = e.data;
            }, false);
            source.addEventListener('h2', function (e) {
                console.log("h2", e.data);
                document.getElementById("DHTHumidityValue").innerHTML = e.data;
            }, false);
            source.addEventListener('p2', function (e) {
                console.log("p2", e.data);
                document.getElementById("BMPPressureValue").innerHTML = e.data;
            }, false);
            source.addEventListener('correctedAngle', function (e) {
                console.log("correctedAngle", e.data);
                document.getElementById("WindDirectionValue").innerHTML = e.data;
            }, false);
            source.addEventListener('lux', function (e) {
                console.log("lux", e.data);
                document.getElementById("LightValue").innerHTML = e.data;
            }, false);
            source.addEventListener('rain', function (e) {
                console.log("rain", e.data);
                document.getElementById("PrecipitationValue").innerHTML = e.data;
            }, false);
            source.addEventListener('windspeed', function (e) {
                console.log("windspeed", e.data);
                document.getElementById("WindSpeedValue").innerHTML = e.data;
            }, false);



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
        setInterval(function () {
            // Call a function repetatively with 1 Second interval
            Time_Date();
        }, 1000);
    </script>
</body>

</html>
)=====";