const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<head>
    <title>Kloudtech Weather Data</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!-- <meta http-equiv="refresh"> -->
    <meta charset="utf-8">
    <link rel="icon" type="image/png" href="icon.png">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link
        href="https://fonts.googleapis.com/css2?family=Nunito:ital,wght@0,200..1000;1,200..1000&family=Sen:wght@400..800&display=swap"
        rel="stylesheet">
    <script src="https://kit.fontawesome.com/af2d673681.js" crossorigin="anonymous"></script>
    <!-- <script src="https://cdn.tailwindcss.com"></script> -->
    <!-- <link rel="stylesheet" href="./output.css"> -->
    <style>
        *,:after,:before{--tw-border-spacing-x:0;--tw-border-spacing-y:0;--tw-translate-x:0;--tw-translate-y:0;--tw-rotate:0;--tw-skew-x:0;--tw-skew-y:0;--tw-scale-x:1;--tw-scale-y:1;--tw-pan-x: ;--tw-pan-y: ;--tw-pinch-zoom: ;--tw-scroll-snap-strictness:proximity;--tw-gradient-from-position: ;--tw-gradient-via-position: ;--tw-gradient-to-position: ;--tw-ordinal: ;--tw-slashed-zero: ;--tw-numeric-figure: ;--tw-numeric-spacing: ;--tw-numeric-fraction: ;--tw-ring-inset: ;--tw-ring-offset-width:0px;--tw-ring-offset-color:#fff;--tw-ring-color:rgba(59,130,246,.5);--tw-ring-offset-shadow:0 0 #0000;--tw-ring-shadow:0 0 #0000;--tw-shadow:0 0 #0000;--tw-shadow-colored:0 0 #0000;--tw-blur: ;--tw-brightness: ;--tw-contrast: ;--tw-grayscale: ;--tw-hue-rotate: ;--tw-invert: ;--tw-saturate: ;--tw-sepia: ;--tw-drop-shadow: ;--tw-backdrop-blur: ;--tw-backdrop-brightness: ;--tw-backdrop-contrast: ;--tw-backdrop-grayscale: ;--tw-backdrop-hue-rotate: ;--tw-backdrop-invert: ;--tw-backdrop-opacity: ;--tw-backdrop-saturate: ;--tw-backdrop-sepia: ;--tw-contain-size: ;--tw-contain-layout: ;--tw-contain-paint: ;--tw-contain-style: }::backdrop{--tw-border-spacing-x:0;--tw-border-spacing-y:0;--tw-translate-x:0;--tw-translate-y:0;--tw-rotate:0;--tw-skew-x:0;--tw-skew-y:0;--tw-scale-x:1;--tw-scale-y:1;--tw-pan-x: ;--tw-pan-y: ;--tw-pinch-zoom: ;--tw-scroll-snap-strictness:proximity;--tw-gradient-from-position: ;--tw-gradient-via-position: ;--tw-gradient-to-position: ;--tw-ordinal: ;--tw-slashed-zero: ;--tw-numeric-figure: ;--tw-numeric-spacing: ;--tw-numeric-fraction: ;--tw-ring-inset: ;--tw-ring-offset-width:0px;--tw-ring-offset-color:#fff;--tw-ring-color:rgba(59,130,246,.5);--tw-ring-offset-shadow:0 0 #0000;--tw-ring-shadow:0 0 #0000;--tw-shadow:0 0 #0000;--tw-shadow-colored:0 0 #0000;--tw-blur: ;--tw-brightness: ;--tw-contrast: ;--tw-grayscale: ;--tw-hue-rotate: ;--tw-invert: ;--tw-saturate: ;--tw-sepia: ;--tw-drop-shadow: ;--tw-backdrop-blur: ;--tw-backdrop-brightness: ;--tw-backdrop-contrast: ;--tw-backdrop-grayscale: ;--tw-backdrop-hue-rotate: ;--tw-backdrop-invert: ;--tw-backdrop-opacity: ;--tw-backdrop-saturate: ;--tw-backdrop-sepia: ;--tw-contain-size: ;--tw-contain-layout: ;--tw-contain-paint: ;--tw-contain-style: }/*! tailwindcss v3.4.14 | MIT License | https://tailwindcss.com*/*,:after,:before{box-sizing:border-box;border:0 solid #e5e7eb}:after,:before{--tw-content:""}:host,html{line-height:1.5;-webkit-text-size-adjust:100%;-moz-tab-size:4;-o-tab-size:4;tab-size:4;font-family:ui-sans-serif,system-ui,sans-serif,Apple Color Emoji,Segoe UI Emoji,Segoe UI Symbol,Noto Color Emoji;font-feature-settings:normal;font-variation-settings:normal;-webkit-tap-highlight-color:transparent}body{line-height:inherit}hr{height:0;color:inherit;border-top-width:1px}abbr:where([title]){-webkit-text-decoration:underline dotted;text-decoration:underline dotted}h1,h2,h3,h4,h5,h6{font-size:inherit;font-weight:inherit}a{color:inherit;text-decoration:inherit}b,strong{font-weight:bolder}code,kbd,pre,samp{font-family:ui-monospace,SFMono-Regular,Menlo,Monaco,Consolas,Liberation Mono,Courier New,monospace;font-feature-settings:normal;font-variation-settings:normal;font-size:1em}small{font-size:80%}sub,sup{font-size:75%;line-height:0;position:relative;vertical-align:baseline}sub{bottom:-.25em}sup{top:-.5em}table{text-indent:0;border-color:inherit;border-collapse:collapse}button,input,optgroup,select,textarea{font-family:inherit;font-feature-settings:inherit;font-variation-settings:inherit;font-size:100%;font-weight:inherit;line-height:inherit;letter-spacing:inherit;color:inherit;margin:0;padding:0}button,select{text-transform:none}button,input:where([type=button]),input:where([type=reset]),input:where([type=submit]){-webkit-appearance:button;background-color:transparent;background-image:none}:-moz-focusring{outline:auto}:-moz-ui-invalid{box-shadow:none}progress{vertical-align:baseline}::-webkit-inner-spin-button,::-webkit-outer-spin-button{height:auto}[type=search]{-webkit-appearance:textfield;outline-offset:-2px}::-webkit-search-decoration{-webkit-appearance:none}::-webkit-file-upload-button{-webkit-appearance:button;font:inherit}summary{display:list-item}blockquote,dd,dl,figure,h1,h2,h3,h4,h5,h6,hr,p,pre{margin:0}fieldset{margin:0}fieldset,legend{padding:0}menu,ol,ul{list-style:none;margin:0;padding:0}dialog{padding:0}textarea{resize:vertical}input::-moz-placeholder,textarea::-moz-placeholder{opacity:1;color:#9ca3af}input::placeholder,textarea::placeholder{opacity:1;color:#9ca3af}[role=button],button{cursor:pointer}:disabled{cursor:default}audio,canvas,embed,iframe,img,object,svg,video{display:block;vertical-align:middle}img,video{max-width:100%;height:auto}[hidden]:where(:not([hidden=until-found])){display:none}.mt-20{margin-top:5rem}.flex{display:flex}.grid{display:grid}.hidden{display:none}.size-10\/12{width:83.333333%;height:83.333333%}.size-5{width:1.25rem;height:1.25rem}.max-w-64{max-width:16rem}.max-w-xs{max-width:20rem}.grid-cols-3{grid-template-columns:repeat(3,minmax(0,1fr))}.place-content-center{place-content:center}.gap-4{gap:1rem}.overflow-hidden{overflow:hidden}.text-center{text-align:center}.text-sm{font-size:.875rem;line-height:1.25rem}.text-xl{font-size:1.25rem;line-height:1.75rem}.text-xs{font-size:.75rem;line-height:1rem}.leading-6{line-height:1.5rem}body{font-family:Arial,sans-serif;margin:0;padding:0;animation:bgcolor 1s linear infinite;animation-direction:alternate}header{background-color:#333;color:#fff;padding:1em;text-align:center;display:flex;justify-content:center;align-items:center;position:relative}.logo{height:3rem;position:absolute;left:1rem}main{display:flex;flex-direction:column;align-items:center;padding:2em}.grid-container{display:grid;grid-template-columns:repeat(3,1fr);gap:10px}.polygon:nth-child(3n+2){transform:translateY(50%)}.grid{color:#fafdf6}.polygon{display:inline-block;background-color:#2d2a32;aspect-ratio:1/cos(30deg);clip-path:polygon(50% -50%,100% 50%,50% 150%,0 50%);transition:color .25s,background-color .25s,scale .25s}.polygon:hover,button:hover{background-color:#ffd900!important;color:#2d2a32;scale:1.05}.font-nunito{font-family:Nunito,sans-serif!important}.button-section{text-align:center}.button{background-color:#333;color:#fff;border:none;padding:10px 20px;font-size:16px;cursor:pointer;border-radius:10px;box-shadow:0 0 10px rgba(0,0,0,.1)}.time-date-section{margin-top:2em;text-align:center}.units{font-size:.8em}.down{background-color:red}@media (min-width:640px){.sm\:mt-20{margin-top:5rem}.sm\:inline{display:inline}.sm\:size-5{width:1.25rem;height:1.25rem}.sm\:size-8\/12{width:66.666667%;height:66.666667%}.sm\:text-2xl{font-size:1.5rem;line-height:2rem}.sm\:text-lg{font-size:1.125rem;line-height:1.75rem}.sm\:text-sm{font-size:.875rem;line-height:1.25rem}}@media (min-width:768px){.md\:size-7\/12{width:58.333333%;height:58.333333%}.md\:size-8{width:2rem;height:2rem}.md\:text-2xl{font-size:1.5rem;line-height:2rem}.md\:text-3xl{font-size:1.875rem;line-height:2.25rem}.md\:text-base{font-size:1rem;line-height:1.5rem}}@media (min-width:1024px){.lg\:mt-32{margin-top:8rem}.lg\:size-10{width:2.5rem;height:2.5rem}.lg\:size-6\/12{width:50%;height:50%}.lg\:text-3xl{font-size:1.875rem;line-height:2.25rem}.lg\:text-4xl{font-size:2.25rem;line-height:2.5rem}}
    </style>

</head>

<body>
    <header>

        <svg class="logo size-5 sm:size-5 md:size-8 lg:size-10" viewBox="0 0 1000 1000">
            <path fill="white"
                d="M143.74,240.62l108.36-62.6v504.11l-88.65,88.65-19.72-11.39c-28.79-16.6-46.51-47.3-46.51-80.55v-357.65c0-33.25,17.72-63.95,46.51-80.55Z" />
            <path fill="white"
                d="M753.15,181.09l-408.02,408.02V124.35l108.36-62.6c28.79-16.6,64.23-16.6,93.02,0l206.64,119.34Z" />
            <path fill="white"
                d="M902.76,321.17v357.65c0,33.25-17.72,63.95-46.51,80.55l-19.72,11.39-270.77-270.77,270.77-270.77,19.72,11.39c28.79,16.6,46.51,47.3,46.51,80.55Z" />
            <path fill="#FBD008"
                d="M753.15,818.91l-206.64,119.34c-28.79,16.6-64.23,16.6-93.02,0l-206.64-119.34,253.15-253.15,253.15,253.15Z" />

        </svg>
        <!-- <h1>Kloudtech Weather Data</h1> -->
        <h1 class="text-sm sm:text-lg md:text-2xl lg:text-3xl">Kloudtech Weather Data</h1>

    </header>
    <main>
        <div
            class="grid grid-cols-3 gap-4 text-center font-nunito size-10/12 sm:size-8/12 md:size-7/12 lg:size-6/12 leading-6">
            <!--BME Temperature-->
            <div class="humidity max-w-xs max-w-64 overflow-hidden polygon place-content-center">
                <div>
                    <i class="fa-solid fa-temperature-empty text-xs sm:text-sm md:text-base"></i>
                    <div class="hidden sm:inline text-xs sm:text-sm md:text-base">Temperature</div>
                </div>
                <div class="text-xl sm:text-2xl md:text-3xl lg:text-4xl">
                    <span id="BME1TemperatureValue">0</span>
                    <!-- <sup class="units">&deg;C</sup> -->
                    <span class="units">&deg;C</span>
                </div>
            </div>

            <!--BME Humidity-->
            <div class="humidity max-w-xs max-w-64 overflow-hidden polygon place-content-center">
                <div>
                    <i class="fa-solid fa-water text-xs sm:text-sm md:text-base"></i>
                    <div class="hidden sm:inline text-xs sm:text-sm md:text-base">Humidity</div>
                </div>
                <div class="text-xl sm:text-2xl md:text-3xl lg:text-4xl">
                    <span id="BME1HumidityValue">0</span>
                    <!-- <sup class="units">%</sup> -->
                    <span class="units">%</span>
                </div>
            </div>
            <!--BME Pressure-->
            <div class="humidity max-w-xs max-w-64 overflow-hidden polygon place-content-center">
                <div>
                    <i class="fa-solid fa-arrows-to-circle text-xs sm:text-sm md:text-base"></i>
                    <div class="hidden sm:inline text-xs sm:text-sm md:text-base">Pressure</div>
                </div>
                <div class="text-xl sm:text-2xl md:text-3xl lg:text-4xl">
                    <span id="BME1PressureValue">0</span>
                    <!-- <sup class="units">mb</sup> -->
                    <span class="units">mb</span>
                </div>
            </div>

            <!--Wind Speed-->
            <div class="max-w-xs max-w-64 overflow-hidden polygon place-content-center">
                <div>
                    <i class="fa-solid fa-wind text-xs sm:text-sm md:text-base"></i>
                    <div class="hidden sm:inline text-xs sm:text-sm md:text-base">Wind Speed</div>
                </div>
                <div class="text-xl sm:text-2xl md:text-3xl lg:text-4xl">
                    <span id="WindSpeedValue">0</span>
                    <span class="units">kph</span>
                </div>
            </div>

        </div>


        <section class="button-section mt-20 sm:mt-20 md:mt-30 lg:mt-32 xl:mt-36 2xl:mt-40">
            <button class="button" onclick="refreshData()">Refresh Data</button>
        </section>
        <section class="time-date-section">
            <i class="far fa-clock" style="font-size:1.0rem;color:#312c04;"></i>
            <span style="font-size:1.0rem;">Time: </span>
            <span id="time" style="font-size:1.0rem;"></span>

            <i class="far fa-calendar-alt" style="font-size:1.0rem;color:#312c04" ;></i>
            <span style="font-size:1.0rem;">Date: </span>
            <span id="date" style="font-size:1.0rem;"></span>
        </section>
    </main>
    <script>
        setInterval(function () {
            getBME1TemperatureData();
            getBME1HumidityData();
            getBME1PressureData();
            // getBME2TemperatureData();
            // getBME2HumidityData();
            // getBME2PressureData();
            // getBME3TemperatureData();
            // getBME3HumidityData();
            // getBME3PressureData();
            // getWindDirectionData();
            // getLightData();
            // getUVData();
            // getPrecipitationData();
            getWindSpeedData();
            // getGustData();
        }, 60000);

        const noData = "No data received";

        setInterval(function () {
            // Call a function repetatively with 1 Second interval
            Time_Date();
        }, 1000);

        // BME Temperature 1
        function getBME1TemperatureData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                document.getElementById("BME1TemperatureValue").innerHTML =
                    this.responseText;
            };
            xhttp.open("GET", "readBME1temp", true);
            xhttp.send();
        }
        // BME Humidity 1
        function getBME1HumidityData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("BME1HumidityValue").innerHTML =
                        this.responseText;
                }
            };
            xhttp.open("GET", "readBME1humid", true);
            xhttp.send();
            console.log(xhttp.readyState);
        }

        // BME Pressure 1
        function getBME1PressureData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("BME1PressureValue").innerHTML =
                        this.responseText;
                }
            };
            xhttp.open("GET", "readBME1pres", true);
            xhttp.send();
        }

        // // BME Temperature 2
        // function getBME2TemperatureData() {
        //     var xhttp = new XMLHttpRequest();
        //     xhttp.onreadystatechange = function () {
        //         document.getElementById("BME2TemperatureValue").innerHTML =
        //             this.responseText;
        //     };
        //     xhttp.open("GET", "readBME2temp", true);
        //     xhttp.send();
        // }
        // // BME Humidity 2
        // function getBME2HumidityData() {
        //     var xhttp = new XMLHttpRequest();
        //     xhttp.onreadystatechange = function () {
        //         if (this.readyState == 4 && this.status == 200) {
        //             document.getElementById("BME2HumidityValue").innerHTML =
        //                 this.responseText;
        //         }
        //     };
        //     xhttp.open("GET", "readBME2humid", true);
        //     xhttp.send();
        //     console.log(xhttp.readyState);
        // }

        // // BME Pressure 2
        // function getBME2PressureData() {
        //     var xhttp = new XMLHttpRequest();
        //     xhttp.onreadystatechange = function () {
        //         if (this.readyState == 4 && this.status == 200) {
        //             document.getElementById("BME2PressureValue").innerHTML =
        //                 this.responseText;
        //         }
        //     };
        //     xhttp.open("GET", "readBME2pres", true);
        //     xhttp.send();
        // }
        // // BME Temperature 3
        // function getBME3TemperatureData() {
        //     var xhttp = new XMLHttpRequest();
        //     xhttp.onreadystatechange = function () {
        //         document.getElementById("BME3TemperatureValue").innerHTML =
        //             this.responseText;
        //     };
        //     xhttp.open("GET", "readBME3temp", true);
        //     xhttp.send();
        // }
        // // BME Humidity 3
        // function getBME3HumidityData() {
        //     var xhttp = new XMLHttpRequest();
        //     xhttp.onreadystatechange = function () {
        //         if (this.readyState == 4 && this.status == 200) {
        //             document.getElementById("BME3HumidityValue").innerHTML =
        //                 this.responseText;
        //         }
        //     };
        //     xhttp.open("GET", "readBME3humid", true);
        //     xhttp.send();
        //     console.log(xhttp.readyState);
        // }

        // // BME Pressure 3
        // function getBME3PressureData() {
        //     var xhttp = new XMLHttpRequest();
        //     xhttp.onreadystatechange = function () {
        //         if (this.readyState == 4 && this.status == 200) {
        //             document.getElementById("BME3PressureValue").innerHTML =
        //                 this.responseText;
        //         }
        //     };
        //     xhttp.open("GET", "readBME3pres", true);
        //     xhttp.send();
        // }

        // function getPrecipitationData() {
        //     var xhttp = new XMLHttpRequest();
        //     xhttp.onreadystatechange = function () {
        //         if (this.readyState == 4 && this.status == 200) {
        //             document.getElementById("PrecipitationValue").innerHTML =
        //                 this.responseText;
        //         }
        //     };
        //     xhttp.open("GET", "readPrecipitation", true);
        //     xhttp.send();
        // }

        // Wind speed
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

        // function getGustData() {
        //     var xhttp = new XMLHttpRequest();
        //     xhttp.onreadystatechange = function () {
        //         if (this.readyState == 4 && this.status == 200) {
        //             document.getElementById("GustValue").innerHTML =
        //                 this.responseText;
        //         }
        //     };
        //     xhttp.open("GET", "readGust", true);
        //     xhttp.send();
        // }

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
            getBME1TemperatureData();
            getBME1HumidityData();
            getBME1PressureData();
            // getBME2TemperatureData();
            // getBME2HumidityData();
            // getBME2PressureData();
            // getBME3TemperatureData();
            // getBME3HumidityData();
            // getBME3PressureData();
            // getWindDirectionData();
            // getLightData();
            // getUVData();
            // getPrecipitationData();
            getWindSpeedData();            
            // getGustData();
        }

    </script>
</body>

</html>
)=====";