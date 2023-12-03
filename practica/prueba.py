<!DOCTYPE html>
<html>
<head>
	<title>Velocidad del viento en distritos sin electricidad</title>
	<style>
		body {
			background-image: url('https://fondosmil.com/fondo/5.jpg');
			background-repeat: no-repeat;
			background-size: cover;
		}
        header {
            background-color: #333;
            color: rgb(9, 24, 44);
            text-align: center;
            padding: 20px;
            font-size: 1.5em;
        }
		h1 {
			text-align: center;
			color: white;
			font-size: 36px;
			margin-top: 50px;
		}

		canvas {
			margin: 20px auto;
			display: block;
		}
        nav {
            background-color: #f2f2f2;
            overflow: hidden;
        }
        nav a {
            float: left;
            display: block;
            color: #333;
            text-align: center;
            padding: 14px 16px;
            text-decoration: none;
        }
        nav a:hover {
            background-color: #ddd;
            color: black;
        }
	</style>
</head>

<body>
    <nav>
        <a href="#">Inicio</a>
        <a href="#">Sobre Nosotros</a>
        <a href="#">Contacto</a>
    </nav>
	<h1>Velocidad del viento en distritos sin electricidad</h1>

	<div style="text-align: center;">
		<canvas id="myChart"></canvas>
	</div>

	<script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
	<script>
		var ctx = document.getElementById('myChart').getContext('2d');
		var myChart = new Chart(ctx, {
			type: 'bar',
			data: {
				labels: ['San Juan', 'San Martin', 'Barranco', 'Villa', 'Victoria'],
				datasets: [{
					label: 'Velocidad del viento (m/s)',
					data: [3, 5, 7, 2, 6],
					backgroundColor: [
						'rgba(255, 99, 132, 0.2)',
						'rgba(54, 162, 235, 0.2)',
						'rgba(255, 206, 86, 0.2)',
						'rgba(75, 192, 192, 0.2)',
						'rgba(153, 102, 255, 0.2)',
					],
					borderColor: [
						'rgba(255, 99, 132, 1)',
						'rgba(54, 162, 235, 1)',
						'rgba(255, 206, 86, 1)',
						'rgba(75, 192, 192, 1)',
						'rgba(153, 102, 255, 1)',
					],
					borderWidth: 1
				}]
			},
			options: {
				scales: {
					y: {
						beginAtZero: true
					}
				}
			}
		});
	</script>
</body>
</html>